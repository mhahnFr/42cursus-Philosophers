#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>

# include "state.h"
# include "fork.h"

/*
 * Represents a philosopher. Contains the index of that specific philosopher,
 * its state and an indicator wether he has died.
 */
struct s_philo {
	size_t			index;
	pthread_t		thread;
	struct s_fork	fork;
	bool			has_died;
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
 * Starts simulating the given philosopher.
 */
void			philo_run(struct s_philo *this);

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
