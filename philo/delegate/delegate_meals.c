#include "delegate.h"

void	delegate_increase_full_philos(struct s_delegate *this)
{
	pthread_mutex_lock(&this->full_philos_mutex);
	this->full_philos += 1;
	pthread_mutex_unlock(&this->full_philos_mutex);
}

int	delegate_get_full_philos(struct s_delegate *this)
{
	int	ret;

	pthread_mutex_lock(&this->full_philos_mutex);
	ret = this->full_philos;
	pthread_mutex_unlock(&this->full_philos_mutex);
	return (ret);
}
