#include <unistd.h>

#include "philo.h"
#include "delegate/delegate.h"

enum e_state	philo_sleep_or_die(struct s_philo *this, int time)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	if (time > this->delegate->time_to_die)
	{
		usleep(this->delegate->time_to_die * 1000);
		return (DIED);
	}
	usleep(time * 1000);
	return (SLEEPING);
}

enum e_state	philo_eat(struct s_philo *this, int time)
{
	struct timeval	t;

	// ...
	usleep(time * 1000);
	// ...
	gettimeofday(&t, NULL);
	if (delegate_get_time_diff(&t, &this->last_eat_time)
		>= this->delegate->time_to_die)
		return (DIED);
	this->last_eat_time = t;
	return (EATING);
}
