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
	delegate->time_to_die = ft_atoi(argv[2]);
	delegate->time_to_eat = ft_atoi(argv[3]);
	delegate->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		delegate->meal_count = ft_atoi(argv[5]);
	return (delegate);
}

int	main(const int argc, const char **argv)
{
	struct s_delegate	*delegate;

	delegate = cli(argv, argc);
	if (delegate == NULL)
	{
		printf("Usage: philo no_of_philos time_to_die time_to_eat"
			"time_to_sleep [meal_count]\n");
		return (1);
	}
	delegate_delete(delegate);
	return (0);
}
