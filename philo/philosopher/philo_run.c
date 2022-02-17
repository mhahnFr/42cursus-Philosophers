#include <stdio.h>
#include <unistd.h>

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

static bool	philo_await_start(struct s_philo *this)
{
	while (delegate_simulation_ongoing(this->delegate)
		&& !delegate_simulation_started(this->delegate))
		usleep(50);
	if (!delegate_simulation_ongoing(this->delegate))
		return (false);
	return (true);
}

void	philo_run(struct s_philo *this)
{
	if (!philo_await_start(this))
		return ;
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
			delegate_print(this->delegate, this->index, " has died");
			delegate_mark_simulation(this->delegate, false);
		}
	}
}
