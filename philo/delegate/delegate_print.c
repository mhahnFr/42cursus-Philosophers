#include <stdio.h>

#include "delegate.h"

bool	delegate_print(struct s_delegate *this, size_t index, char *what)
{
	bool	ret;

	pthread_mutex_lock(&this->print_mutex);
	ret = this->simulation_running;
	if (ret)
		printf("%d %zu %s\n", delegate_get_time_stamp(this), index, what);
	pthread_mutex_unlock(&this->print_mutex);
	return (ret);
}
