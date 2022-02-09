#include <unistd.h>
#include <stdio.h>

#include "philo.h"
#include "delegate/delegate.h"

static long	philo_now(void)
{
	struct timeval	t;
	
	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

static enum e_state	philo_sleep(struct s_philo *this, int time, enum e_state state)
{
	long	start;
	long	now;
	
	start = philo_now();
	now = start;
	while (now < start + time)
	{
		usleep(100);
		now = philo_now();
		if (!delegate_simulation_ongoing(this->delegate))
			return (STOPPED);
		if (this->last_eat_time + this->delegate->time_to_die < now)
			return (DIED);
	}
	return (state);
}

enum e_state	philo_sleep_or_die(struct s_philo *this, int time)
{
	return (philo_sleep(this, time, SLEEPING));
}

enum e_state	philo_eat(struct s_philo *this, int time)
{
	enum e_state	state;
	size_t			index;

	while (!fork_take(&this->fork))
	{
		state = philo_sleep(this, 100, EATING);
		if (state != EATING)
			return (state);
	}
	delegate_print(this->delegate, this->index, " has taken a fork");
	index = this->index - 1;
	if (this->index == 0)
		index = this->delegate->philo_count - 1;
	while (!fork_take(&this->delegate->philosophers[index].fork))
	{
		state = philo_sleep(this, 100, EATING);
		if (state != EATING)
			return (state);
	}
	delegate_print(this->delegate, this->index, " has taken a fork");
	delegate_print(this->delegate, this->index, " is eating");
	this->last_eat_time = philo_now();
	state = philo_sleep(this, time, EATING);
	fork_drop(&this->fork);
	fork_drop(&this->delegate->philosophers[index].fork);
	return (state);
}
