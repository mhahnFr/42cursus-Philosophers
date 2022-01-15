#include <pthread.h>

#include "delegate.h"

static void	*delegate_thread_helper(void *arg)
{
	struct s_thread_helper	*helper;

	helper = (struct s_thread_helper *) arg;
	philo_run(helper->philo, helper->delegate);
	return (NULL);
}

void	delegate_start_simulation(struct s_delegate *this)
{
	int						i;
	struct s_thread_helper	helper;

	i = 0;
	while (i < this->philo_count)
	{
		helper.delegate = this;
		helper.philo = (this->philosophers) + i; // FIXME Add proper argument passing
		pthread_create(
			&helper.philo->thread,
			NULL,
			delegate_thread_helper,
			&helper);
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
