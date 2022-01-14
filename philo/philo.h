#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>

# include "state.h"

/*
 * Represents a philosopher. Contains the index of that specific philosopher,
 * its state and an indicator wether he has died.
 */
struct s_philo {
	size_t			index;
	bool			has_died;
	pthread_t		thread;
	enum e_state	state;
};

/*
 * Allocates a new philosopher object. Returns either the newly allocated
 * object or null if the allocation failed.
 */
struct s_philo	*philo_new(size_t index);

/*
 * Initializes the given philosopher object. Does nothing if no object is
 * given.
 */
void			philo_create(struct s_philo *this, size_t index);

/*
 * Destroys the given philosopher object. Does nothing if no object is given.
 */
void			philo_destroy(struct s_philo *this);

/*
 * Destroys and frees the given philosopher object. Does nothing if no object
 * is given.
 */
void			philo_delete(struct s_philo *this);

#endif
