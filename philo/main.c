#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static bool	cli(const char **argv, const int argc)
{
	size_t	i;

	if (argc < 5 || argc > 6)
		return (false);
	i = 0;
	while (argv[i++] != NULL)
	{
		if (i == 6)
			;
	}
	return (true);
}

int	main(const int argc, const char **argv)
{
	if (!cli(argv, argc))
	{
		printf("Usage: philo no_of_philos time_to_die time_to_eat"
			"time_to_sleep [meal_count]\n");
		return (1);
	}
	return (0);
}
