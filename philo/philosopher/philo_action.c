#include <unistd.h>
#include <stdio.h>

#include "philo.h"
#include "delegate/delegate.h"

enum e_state	philo_sleep_or_die(struct s_philo *this, int time)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	if (time > this->delegate->time_to_die)
	{
		usleep(this->delegate->time_to_die * 1000);
		return (DIED);
	}
	usleep(time * 1000);
	return (SLEEPING);
}

enum e_state	philo_eat(struct s_philo *this, int time)
{
	struct timeval	t;

	while (!fork_take(&this->fork))
		usleep(100);
	pthread_mutex_lock(&this->delegate->print_mutex);
	printf("%d %zu has taken a fork\n", delegate_get_time_stamp(this->delegate), this->index);
	pthread_mutex_unlock(&this->delegate->print_mutex);
	while (!fork_take(&this->delegate->philosophers[this->index - 1].fork))
		usleep(100);
	pthread_mutex_lock(&this->delegate->print_mutex);
	printf("%d %zu has taken a fork\n", delegate_get_time_stamp(this->delegate), this->index);
	printf("%d %zu is eating\n", delegate_get_time_stamp(this->delegate), this->index);
	pthread_mutex_unlock(&this->delegate->print_mutex);
	gettimeofday(&t, NULL);
	if (delegate_get_time_diff(&t, &this->last_eat_time)
		>= this->delegate->time_to_die)
		return (DIED);
	this->last_eat_time = t;
	usleep(time * 1000);
	fork_drop(&this->fork);
	fork_drop(&this->delegate->philosophers[this->index - 1].fork);
	return (EATING);
}
