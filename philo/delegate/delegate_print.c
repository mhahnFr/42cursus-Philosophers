#include <stdio.h>

#include "delegate.h"

void	delegate_print(struct s_delegate *this, size_t index, char *what)
{
	if (delegate_simulation_ongoing(this))
	{
		pthread_mutex_lock(&this->print_mutex);
		printf("%d %zu %s\n", delegate_get_time_stamp(this), index, what);
		pthread_mutex_unlock(&this->print_mutex);
	}
}
