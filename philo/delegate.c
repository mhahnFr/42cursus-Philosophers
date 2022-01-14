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
	i = 0;
	while (i < philo_count)
	{
		philo_create(&this->philosophers[i], i);
		i++;
	}
}

void	delegate_destroy(struct s_delegate *this)
{
	long	i;

	if (this == NULL)
		return ;
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
