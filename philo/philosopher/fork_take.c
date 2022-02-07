#include "fork.h"

bool	fork_is_taken(struct s_fork *this)
{
	bool	taken;
	
	pthread_mutex_lock(&this->mutex);
	taken = this->taken;
	pthread_mutex_unlock(&this->mutex);
	return (taken);
}

bool	fork_take(struct s_fork *this)
{
	bool	taken;

    taken = false;
	pthread_mutex_lock(&this->mutex);
	if (!this->taken)
	{
		this->taken = true;
		taken = true;
	}
	pthread_mutex_unlock(&this->mutex);
	return (taken);
}
