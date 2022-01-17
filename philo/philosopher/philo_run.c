#include <stdio.h>

#include "delegate/delegate.h"
#include "philo.h"

enum e_state	philo_do_or_die(
		struct s_philo *this,
		enum e_state action)
{
	if (action == SLEEPING)
	{
		printf("%d %zu is sleeping\n", delegate_get_time_stamp(this->delegate),
			this->index);
		action = philo_sleep_or_die(this, this->delegate->time_to_sleep);
	}
	else if (action == EATING)
	{
		printf("%d %zu is thinking\n", delegate_get_time_stamp(this->delegate),
			this->index);
		action = philo_eat(this, this->delegate->time_to_eat);
	}
	return (action);
}

void	philo_run(struct s_philo *this)
{
	while (!this->has_died)
	{
		if (this->state == EATING || this->state == UNDEFINED)
			this->state = philo_do_or_die(this, SLEEPING);
		else if (this->state == THINKING || this->state == SLEEPING)
			this->state = philo_do_or_die(this, EATING);
		if (this->state == DIED)
		{
			this->has_died = true;
			delegate_mark_simulation(this->delegate, false);
			printf("%d %zu has died\n", delegate_get_time_stamp(this->delegate),
				this->index);
		}
	}
}
