#ifndef DELEGATE_H
# define DELEGATE_H

# include <stddef.h>

# include "philo.h"

/*
 * A structure with the parameters of the simulation. Contains the philosophers
 * themselves as well as their count and the timeout values.
 */
struct s_delegate {
	size_t			time_to_sleep;
	size_t			time_to_eat;
	size_t			time_to_die;
	int				meal_count;
	size_t			philo_count;
	struct s_philo	philosophers[];
};

/*
 * Allocates and returns a new delegate object with the indicated number of
 * philosophers. Rerturns either the newly allocated object or null if the
 * allocation failed.
 */
struct s_delegate	*delegate_new(size_t philo_count);

/*
 * Initializes the given delegate object. Does nothing if no object is given.
 */
void				delegate_create(
						struct s_delegate *this,
						size_t philo_count);

/*
 * Destroys the given delegate object. Does nothing if no object is given.
 */
void				delegate_destroy(struct s_delegate *this);

/*
 * Destroys and frees the given delegate object. Does nothing if no object is
 * given.
 */
void				delegate_delete(struct s_delegate *this);

#endif
