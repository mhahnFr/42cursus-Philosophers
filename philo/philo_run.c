#include <stdio.h>

#include "delegate.h"
#include "philo.h"

enum e_state	philo_do_or_die(
		struct s_philo *this,
		struct s_delegate *delegate,
		enum e_state action)
{
	(void) delegate;
	(void) action;
	(void) this;
	return (DIED);
}

void	philo_run(struct s_philo *this, struct s_delegate *delegate)
{
	while (!this->has_died)
	{
		if (this->state == EATING)
			this->state = philo_do_or_die(this, delegate, EATING);
		else if (this->state == SLEEPING)
			this->state = philo_do_or_die(this, delegate, SLEEPING);
		else if (this->state == THINKING || this->state == UNDEFINED)
			this->state = philo_do_or_die(this, delegate, THINKING);
		if (this->state == DIED)
		{
			this->has_died = true;
			delegate_stop_simulation(delegate, this);
		}
	}
}
