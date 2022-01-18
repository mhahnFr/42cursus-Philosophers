#include "delegate.h"

int	delegate_get_time_stamp(struct s_delegate *this)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (delegate_get_time_diff(&t, (struct timeval *) &this->start_time));
}

int	delegate_get_time_diff(struct timeval *t1, struct timeval *t2)
{
	return ((t1->tv_sec - t2->tv_sec) * 1000
		+ (t1->tv_usec - t2->tv_usec) / 1000);
}
