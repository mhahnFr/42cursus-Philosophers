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

static bool	philo_sleep(struct s_philo *this, int time)
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
			return (false);
	}
	return (true);
}

enum e_state	philo_sleep_or_die(struct s_philo *this, int time)
{
	if (philo_sleep(this, time))
		return (SLEEPING);
	return (DIED);
}

enum e_state	philo_eat(struct s_philo *this, int time)
{
	enum e_state	state;
	size_t			index;

	while (!fork_take(&this->fork))
		if (!philo_sleep(this, 100))
			return (DIED);
	pthread_mutex_lock(&this->delegate->print_mutex);
	printf("%d %zu has taken a fork\n", delegate_get_time_stamp(this->delegate), this->index);
	pthread_mutex_unlock(&this->delegate->print_mutex);
	index = this->index - 1;
	if (this->index == 0)
		index = this->delegate->philo_count - 1;
	while (!fork_take(&this->delegate->philosophers[index].fork))
		if (!philo_sleep(this, 100))
			return (DIED);
	pthread_mutex_lock(&this->delegate->print_mutex);
	printf("%d %zu has taken a fork\n", delegate_get_time_stamp(this->delegate), this->index);
	printf("%d %zu is eating\n", delegate_get_time_stamp(this->delegate), this->index);
	pthread_mutex_unlock(&this->delegate->print_mutex);
	this->last_eat_time = philo_now();
	state = philo_sleep(this, time);
	fork_drop(&this->fork);
	fork_drop(&this->delegate->philosophers[index].fork);
	return (state);
}
