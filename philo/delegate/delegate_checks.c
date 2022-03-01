#include <pthread.h>

#include "delegate.h"

bool	delegate_simulation_ongoing(struct s_delegate *this)
{
	bool	ret;

	pthread_mutex_lock(&this->simulation_state_mutex);
	ret = this->simulation_running;
	pthread_mutex_unlock(&this->simulation_state_mutex);
	return (ret);
}
