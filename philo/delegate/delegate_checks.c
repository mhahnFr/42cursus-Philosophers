#include <pthread.h>

#include "delegate.h"

bool	delegate_simulation_started(struct s_delegate *this)
{
	bool	ret;

	pthread_mutex_lock(&this->simulation_state_mutex);
	ret = this->simulation_started;
	pthread_mutex_unlock(&this->simulation_state_mutex);
	return (ret);
}

bool	delegate_get_print_available(struct s_delegate *this)
{
	bool	ret;

	pthread_mutex_lock(&this->print_available_mutex);
	ret = this->print_available;
	pthread_mutex_unlock(&this->print_available_mutex);
	return (ret);
}

bool	delegate_simulation_ongoing(struct s_delegate *this)
{
	bool	ret;

	pthread_mutex_lock(&this->simulation_state_mutex);
	ret = this->simulation_running;
	pthread_mutex_unlock(&this->simulation_state_mutex);
	return (ret);
}
