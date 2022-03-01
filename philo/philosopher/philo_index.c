#include "delegate/delegate.h"
#include "philo.h"

size_t	philo_get_left_index(struct s_philo *this)
{
	if (this->index == 0)
		return (this->delegate->philo_count - 1);
	return (this->index - 1);
}
