#include <stdlib.h>

#include "delegate.h"

struct s_delegate	*delegate_new(size_t philo_count)
{
	struct s_delegate	*this;

	this = malloc(sizeof(struct s_delegate)
			+ philo_count * sizeof(struct s_philo));
	if (this != NULL)
		delegate_create(this, philo_count);
	return (this);
}

void	delegate_create(struct s_delegate *this, size_t philo_count)
{
	if (this == NULL)
		return ;
	// TODO
}

void	delegate_destroy(struct s_delegate *this)
{
	if (this == NULL)
		return ;
}

void	delegate_delete(struct s_delegate *this)
{
	if (this == NULL)
		return ;
	delegate_destroy(this);
	free(this);
}
