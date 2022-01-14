#include "delegate.h"

static bool	delegate_validate_meal_count(struct s_delegate *this)
{
	if (this == NULL)
		return (false);
	if (this->meal_count_set && this->meal_count < 0)
		return (false);
	return (true);
}

bool	delegate_validate(struct s_delegate *this)
{
	return (this != NULL
		&& this->time_to_sleep >= 0
		&& this->time_to_eat >= 0
		&& this->time_to_die >= 0
		&& this->philo_count >= 1
		&& delegate_validate_meal_count(this));
}

void	delegate_invalidate(struct s_delegate *this)
{
	if (this == NULL)
		return ;
	this->time_to_die = -1;
	this->time_to_sleep = -1;
	this->time_to_eat = -1;
	this->philo_count = -1;
	this->meal_count = -1;
	this->meal_count_set = true;
}
