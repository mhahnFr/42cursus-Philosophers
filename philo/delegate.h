#ifndef DELEGATE_H
# define DELEGATE_H

# include <stddef.h>

# include "philo.h"

typedef void *(*t_thread_run)(void *);

/*
 * A structure with the parameters of the simulation. Contains the philosophers
 * themselves as well as their count and the timeout values.
 */
struct s_delegate {
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				philo_count;
	int				meal_count;
	bool			meal_count_set;
	struct s_philo	philosophers[];
};

/*
 * Allocates and returns a new delegate object with the indicated number of
 * philosophers. Rerturns either the newly allocated object or null if the
 * allocation failed.
 */
struct s_delegate	*delegate_new(long philo_count);

/*
 * Initializes the given delegate object. Does nothing if no object is given.
 */
void				delegate_create(
						struct s_delegate *this,
						long philo_count);

/*
 * Validates the values of the given delegate object. Returns true if all
 * values found in the given delegate object are valid, false otherwise.
 * Returns false if no delegate object is given.
 */
bool				delegate_validate(struct s_delegate *this);

/*
 * Invalidates the values of the given delegate object. A call to the method
 * "delegate_validate(struct s_delegate)" will return false after this method
 * has been invoked. Does nothing if no delegate object is given.
 */
void				delegate_invalidate(struct s_delegate *this);

/*
 * Starts the philosophers simulation. For each philosopher, a thread is
 * run.
 */
void				delegate_start_simulation(struct s_delegate *this);

/*
 * Stops the philosophers simulation. Stops all philosopher threads that are
 * still running.
 */
void				delegate_stop_simulation(
						struct s_delegate *this,
						struct s_philo *reason);

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
