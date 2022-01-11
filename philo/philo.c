#include <stdlib.h>

#include "philo.h"

struct s_philo	*philo_new(void)
{
	struct s_philo	*this;

	this = malloc(sizeof(struct s_philo));
	if (this != NULL)
		philo_create(this);
	return (this);
}

void	philo_create(struct s_philo *this)
{
	if (this == NULL)
		return ;
}

void	philo_destroy(struct s_philo *this)
{
}

void	philo_delete(struct s_philo *this)
{
	if (this == NULL)
		return ;
	philo_destroy(this);
	free(this);
}
