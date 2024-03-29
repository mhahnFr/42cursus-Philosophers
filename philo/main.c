#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "delegate/delegate.h"
#include "utils/utils.h"

/*
 * Parses the arguments given on the command line. Returns a newly allocated
 * delegate object or null if either the allocation failed or the number of
 * arguments is wrong. Returns an invalidated delegate object if the arguments
 * themselves are wrong.
 */
static struct s_delegate	*cli(const char **argv, const int argc)
{
	int					philo_count;
	struct s_delegate	*delegate;

	if (argc < 5 || argc > 6 || !ft_isnum(argv[1])
		|| !ft_atoi_error(argv[1], &philo_count))
		return (NULL);
	delegate = delegate_new(philo_count);
	if (delegate == NULL)
		return (NULL);
	if (!ft_isnum(argv[2]) || !ft_isnum(argv[3]) || !ft_isnum(argv[4])
		|| !ft_atoi_error(argv[2], (int *) &delegate->time_to_die)
		|| !ft_atoi_error(argv[3], (int *) &delegate->time_to_eat)
		|| !ft_atoi_error(argv[4], (int *) &delegate->time_to_sleep))
		delegate_invalidate(delegate);
	delegate->meal_count_set = false;
	if (argc > 5)
	{
		if (!ft_isnum(argv[5])
			|| !ft_atoi_error(argv[5], (int *) &delegate->meal_count))
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
	delegate_start_simulation(delegate);
	delegate_delete(delegate);
	return (0);
}
