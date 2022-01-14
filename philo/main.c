#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "delegate.h"
#include "utils/utils.h"

static struct s_delegate	*cli(const char **argv, const int argc)
{
	struct s_delegate	*delegate;

	if (argc < 5 || argc > 6)
		return (NULL);
	delegate = delegate_new(ft_atoi(argv[1]));
	if (delegate == NULL)
		return (NULL);
	if (!ft_atoi_error(argv[2], &delegate->time_to_die)
		|| !ft_atoi_error(argv[3], &delegate->time_to_eat)
		|| !ft_atoi_error(argv[4], &delegate->time_to_sleep))
		delegate_invalidate(delegate);
	delegate->meal_count_set = false;
	if (argc > 5)
	{
		if (!ft_atoi_error(argv[5], &delegate->meal_count))
			delegate_invalidate(delegate);
		delegate->meal_count_set = true;
	}
	return (delegate);
}

int	main(const int argc, const char **argv)
{
	struct s_delegate	*delegate;

	delegate = cli(argv, argc);
	if (delegate == NULL || !delegate_validate(delegate))
	{
		printf("Usage: philo no_of_philos time_to_die time_to_eat "
			"time_to_sleep [meal_count]\n");
		delegate_delete(delegate);
		return (1);
	}
	delegate_delete(delegate);
	return (0);
}
