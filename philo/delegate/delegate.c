#include <stdlib.h>

#include "delegate.h"

struct s_delegate	*delegate_new(long philo_count)
{
	struct s_delegate	*this;

	this = malloc(sizeof(struct s_delegate)
			+ philo_count * sizeof(struct s_philo));
	if (this != NULL)
		delegate_create(this, philo_count);
	return (this);
}

void	delegate_create(struct s_delegate *this, long philo_count)
{
	long	i;

	if (this == NULL)
		return ;
	this->time_to_sleep = 0;
	this->time_to_eat = 0;
	this->time_to_die = 0;
	this->meal_count = -1;
	this->philo_count = philo_count;
	this->simulation_running = false;
	pthread_mutex_init(&this->print_mutex, NULL);
	pthread_mutex_init(&this->simulation_state_mutex, NULL);
	i = 0;
	while (i < philo_count)
	{
		philo_create(&this->philosophers[i], i, this);
		i++;
	}
}

void	delegate_destroy(struct s_delegate *this)
{
	long	i;

	if (this == NULL)
		return ;
	pthread_mutex_destroy(&this->print_mutex);
	pthread_mutex_destroy(&this->simulation_state_mutex);
	i = 0;
	while (i < this->philo_count)
	{
		philo_destroy(&this->philosophers[i]);
		i++;
	}
}

void	delegate_delete(struct s_delegate *this)
{
	if (this == NULL)
		return ;
	delegate_destroy(this);
	free(this);
}
