#include <pthread.h>
#include <unistd.h>

#include "delegate.h"

void	delegate_async_check(struct s_delegate *this)
{
	int	i;

	i = 0;
	while (i < this->philo_count)
	{
		if (this->philosophers[i].has_died)
		{
			delegate_stop_simulation(this, &this->philosophers[i]);
			return ;
		}
		i++;
	}
	usleep(100);
	delegate_async_check(this);
}

void	delegate_start_simulation(struct s_delegate *this)
{
	int	i;

	i = 0;
	while (i < this->philo_count)
	{
		pthread_create(
			&this->philosophers[i].thread,
			NULL,
			(t_thread_run) philo_run,
			(void *) &this->philosophers[i]);
		i++;
	}
	delegate_async_check(this);
}

void	delegate_stop_simulation(
		struct s_delegate *this,
		struct s_philo *reason)
{
	(void) this;
	(void) reason;
}
