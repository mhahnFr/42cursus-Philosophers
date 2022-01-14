#ifndef DELEGATE_H
# define DELEGATE_H

# include <stddef.h>

# include "philo.h"

/*
 * A structure with the parameters of the simulation. Contains the philosophers
 * themselves as well as their count and the timeout values.
 */
struct s_delegate {
	long			time_to_sleep;
	long			time_to_eat;
	long			time_to_die;
	long			philo_count;
	long			meal_count;
	bool			meal_count_set;
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
 * Validates the values of the given delegate object. Returns true if all
 * values found in the given delegate object are valid, false otherwise.
 * Returns false if no delegate object is given.
 */
bool				delegate_validate(struct s_delegate *this);

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
