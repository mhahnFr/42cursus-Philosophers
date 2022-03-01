#include <unistd.h>
#include <stdio.h>

#include "philo.h"
#include "delegate/delegate.h"

/*
 * Returns the current time in milliseconds.
 */
static long	philo_now(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

/*
 * Lets the given philosopher sleep until he slept the given time or he died.
 */
static enum e_state	philo_sleep(
		struct s_philo *this,
		int time,
		enum e_state state)
{
	long	start;
	long	now;

	start = philo_now();
	now = start;
	while (now < start + time)
	{
		usleep(100);
		now = philo_now();
		if (this->last_eat_time + this->delegate->time_to_die < now)
			return (DIED);
	}
	return (state);
}

enum e_state	philo_sleep_or_die(struct s_philo *this, int time)
{
	return (philo_sleep(this, time, SLEEPING));
}

/*
 * Tries to take the given fork. Returns true upon success, false if the given
 * philosopher died or the simulation ended.
 */
static bool	philo_take_fork(
		struct s_philo *this,
		struct s_fork *fork,
		enum e_state *state)
{
	*state = EATING;
	while (!fork_take(fork))
	{
		if (this->last_eat_time + this->delegate->time_to_die < philo_now())
		{
			*state = DIED;
			return (false);
		}
	}
	return (delegate_print(this->delegate, this->index, " has taken a fork"));
}

enum e_state	philo_eat(struct s_philo *this, int time)
{
	enum e_state	state;
	size_t			index;

	index = philo_get_left_index(this);
	if (this->index % 2)
	{
		if (!philo_take_fork(this, &this->fork, &state)
			|| !philo_take_fork(this,
				&this->delegate->philosophers[index].fork, &state))
			return (state);
	}
	else
		if (!philo_take_fork(this,
				&this->delegate->philosophers[index].fork, &state)
			|| !philo_take_fork(this, &this->fork, &state))
			return (state);
	if (!delegate_print(this->delegate, this->index, " is eating"))
		return (STOPPED);
	this->last_eat_time = philo_now();
	state = philo_sleep(this, time, EATING);
	fork_drop(&this->fork);
	fork_drop(&this->delegate->philosophers[index].fork);
	philo_update_meals(this);
	return (state);
}
