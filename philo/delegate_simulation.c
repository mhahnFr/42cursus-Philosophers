#include <pthread.h>

#include "delegate.h"

#include <stdio.h>
void	delegate_start_simulation(struct s_delegate *this)
{
	int	i;

	i = 0;
	while (i < this->philo_count)
	{
		printf("Loop: %zu\n", this->philosophers[i].index);
		pthread_create(
			&this->philosophers[i].thread,
			NULL,
			(t_thread_run) philo_run,
			(void *) &this->philosophers[i]);
		i++;
	}
}

void	delegate_stop_simulation(
		struct s_delegate *this,
		struct s_philo *reason)
{
	(void) this;
	(void) reason;
}
