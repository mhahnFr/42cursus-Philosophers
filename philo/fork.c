#include <stdlib.h>

#include "fork.h"

struct s_fork	*fork_new(void)
{
	struct s_fork	*this;

	this = malloc(sizeof(struct s_fork));
	if (this != NULL)
		fork_create(this);
	return (this);
}

void	fork_create(struct s_fork *this)
{
	if (this == NULL)
		return ;
	this->taken = false;
}

void	fork_destroy(struct s_fork *this)
{
	if (this == NULL)
		return ;
	this->taken = false;
}

void	fork_delete(struct s_fork *this)
{
	if (this == NULL)
		return ;
	fork_destroy(this);
	free(this);
}
