#include "delegate/delegate.h"
#include "philo.h"

void	philo_update_meals(struct s_philo *this)
{
	this->meals += 1;
	if (this->delegate->meal_count_set
		&& this->meals == this->delegate->meal_count)
		delegate_increase_full_philos(this->delegate);
}
