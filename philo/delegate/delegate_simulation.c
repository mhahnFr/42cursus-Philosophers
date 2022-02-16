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
	pthread_mutex_unlock(&this->simulation_state_mutex);
	delegate_stop_simulation(this);
}

void	delegate_start_simulation(struct s_delegate *this)
{
	int	i;

	gettimeofday((struct timeval *) &this->start_time, NULL);
	this->simulation_running = true;
	i = 0;
	while (i < this->philo_count)
	{
		this->philosophers[i].last_eat_time
			= this->start_time.tv_sec * 1000 + this->start_time.tv_usec / 1000;
		pthread_create(
			&this->philosophers[i].thread,
			NULL,
			(t_thread_run) philo_run,
			(void *) &this->philosophers[i]);
		i++;
	}
	delegate_async_check(this);
}

bool	delegate_simulation_ongoing(struct s_delegate *this)
{
	bool	ret;

	pthread_mutex_lock(&this->simulation_state_mutex);
	ret = this->simulation_running;
	pthread_mutex_unlock(&this->simulation_state_mutex);
	return (ret);
}

void	delegate_mark_simulation(struct s_delegate *this, bool running)
{
	pthread_mutex_lock(&this->simulation_state_mutex);
	this->simulation_running = running;
	pthread_mutex_unlock(&this->simulation_state_mutex);
	if (!running)
		pthread_mutex_lock(&this->print_mutex);
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
