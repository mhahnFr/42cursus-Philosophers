#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "delegate.h"

static void	delegate_set_simulation_started(
		struct s_delegate *this,
		bool value)
{
	pthread_mutex_lock(&this->simulation_state_mutex);
	this->simulation_started = value;
	pthread_mutex_unlock(&this->simulation_state_mutex);
}

void	delegate_async_check(struct s_delegate *this)
{
	while (delegate_simulation_ongoing(this))
		usleep(1000);
	delegate_stop_simulation(this);
}

void	delegate_start_simulation(struct s_delegate *this)
{
	int	i;

	i = 0;
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
	gettimeofday((struct timeval *) &this->start_time, NULL);
	delegate_set_simulation_started(this, true);
	delegate_async_check(this);
}

void	delegate_finish_simulation(
			struct s_delegate *this,
			struct s_philo *reason)
{
	pthread_mutex_lock(&this->simulation_state_mutex);
	this->simulation_running = false;
	pthread_mutex_unlock(&this->simulation_state_mutex);
	pthread_mutex_lock(&this->print_available_mutex);
	this->print_available = false;
	pthread_mutex_unlock(&this->print_available_mutex);
	if (reason != NULL)
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
