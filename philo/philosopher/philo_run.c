#include <stdio.h>

#include "delegate/delegate.h"
#include "philo.h"

enum e_state	philo_do_or_die(
		struct s_philo *this,
		enum e_state action)
{
	if (action == SLEEPING)
	{
		delegate_print(this->delegate, this->index, " is sleeping");
		action = philo_sleep_or_die(this, this->delegate->time_to_sleep);
	}
	else if (action == EATING)
	{
		delegate_print(this->delegate, this->index, " is thinking");
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
	        if (this->state == STOPPED)
        	    break ;
		else if (this->state == DIED)
		{
			this->has_died = true;
			delegate_mark_simulation(this->delegate, false);
			delegate_print(this->delegate, this->index, " has died");
		}
	}
}
