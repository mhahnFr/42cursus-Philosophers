#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "delegate.h"

void	delegate_async_check(struct s_delegate *this)
{
	bool	helper;

	pthread_mutex_lock(&this->simulation_state_mutex);
	helper = this->simulation_running;
	while (helper)
	{
		pthread_mutex_unlock(&this->simulation_state_mutex);
		usleep(100); // TODO Better checking time
		pthread_mutex_lock(&this->simulation_state_mutex);
		helper = this->simulation_running;
	}
	delegate_stop_simulation(this);
}

void	delegate_start_simulation(struct s_delegate *this)
{
	int	i;

	gettimeofday((struct timeval *) &this->start_time, NULL);
	i = 0;
	while (i < this->philo_count)
	{
		this->philosophers[i].last_eat_time = this->start_time;
		pthread_create(
			&this->philosophers[i].thread,
			NULL,
			(t_thread_run) philo_run,
			(void *) &this->philosophers[i]);
		i++;
	}
	this->simulation_running = true;
	delegate_async_check(this);
}

void	delegate_mark_simulation(struct s_delegate *this, bool running)
{
	this->simulation_running = running;
}

void	delegate_stop_simulation(struct s_delegate *this)
{
	(void) this;
	// TODO Stop all running threads
}
