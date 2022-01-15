#include <stdio.h>

#include "delegate.h"
#include "philo.h"

enum e_state	philo_do_or_die(
		struct s_philo *this,
		enum e_state action)
{
	(void) action;
	printf("Thread: %zu\n", this->index);
	return (DIED);
}

void	philo_run(struct s_philo *this)
{
	while (!this->has_died)
	{
		if (this->state == EATING)
			this->state = philo_do_or_die(this, EATING);
		else if (this->state == SLEEPING)
			this->state = philo_do_or_die(this, SLEEPING);
		else if (this->state == THINKING || this->state == UNDEFINED)
			this->state = philo_do_or_die(this, THINKING);
		if (this->state == DIED)
		{
			this->has_died = true;
			delegate_stop_simulation(this->delegate, this);
		}
	}
}
