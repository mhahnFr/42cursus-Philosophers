#include <stdlib.h>

#include "philo.h"

struct s_philo	*philo_new(size_t index, struct s_delegate *delegate)
{
	struct s_philo	*this;

	this = malloc(sizeof(struct s_philo));
	if (this != NULL)
		philo_create(this, index, delegate);
	return (this);
}

void	philo_create(
			struct s_philo *this,
			size_t index,
			struct s_delegate *delegate)
{
	if (this == NULL)
		return ;
	this->index = index;
	if (this->index % 2 == 0)
		this->state = UNDEFINED;
	else
		this->state = THINKING;
	this->meals = 0;
	this->delegate = delegate;
	this->has_died = false;
	fork_create(&this->fork);
}

void	philo_destroy(struct s_philo *this)
{
	if (this == NULL)
		return ;
	this->state = UNDEFINED;
	fork_destroy(&this->fork);
}

void	philo_delete(struct s_philo *this)
{
	if (this == NULL)
		return ;
	philo_destroy(this);
	free(this);
}
