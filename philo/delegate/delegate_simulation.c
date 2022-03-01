#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "delegate.h"

void	delegate_async_check(struct s_delegate *this)
{
	if (this->meal_count_set)
	{
		while (delegate_get_full_philos(this) != this->philo_count)
			usleep(10000);
		delegate_finish_simulation(this, NULL);
	}
	delegate_stop_simulation(this);
}

void	delegate_start_simulation(struct s_delegate *this)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&this->simulation_state_mutex);
	while (i < this->philo_count)
	{
		if (pthread_create(
				&this->philosophers[i].thread,
				NULL,
				(t_thread_run) philo_run,
				(void *) &this->philosophers[i]) != 0)
		{
			printf("Could not create thread for philosopher %d!\n", i);
			delegate_finish_simulation(this, NULL);
			delegate_stop_simulation(this);
			return ;
		}
		i++;
	}
	this->simulation_started = true;
	gettimeofday((struct timeval *) &this->start_time, NULL);
	pthread_mutex_unlock(&this->simulation_state_mutex);
	delegate_async_check(this);
}

void	delegate_finish_simulation(
			struct s_delegate *this,
			struct s_philo *reason)
{
	bool	was;

	pthread_mutex_lock(&this->print_mutex);
	was = this->simulation_running;
	this->simulation_running = false;
	pthread_mutex_unlock(&this->print_mutex);
	if (reason != NULL && was)
		printf("%d %zu has died\n", delegate_get_time_stamp(this),
			reason->index);
}

void	delegate_stop_simulation(struct s_delegate *this)
{
	long	i;

	i = 0;
	while (i < this->philo_count)
	{
		pthread_join(this->philosophers[i].thread, NULL);
		i++;
	}
}
