#ifndef FORK_H
# define FORK_H

# include <stdbool.h>
# include <pthread.h>

/*
 * Represents a fork.
 */
struct s_fork {
	pthread_mutex_t	mutex;
	bool			taken;
};

/*
 * Allocates and returns a new fork object. Returns null if the allocation
 * failed.
 */
struct s_fork	*fork_new(void);

/*
 * Initializes the given fork object. Does nothing if no fokr object is given.
 */
void			fork_create(struct s_fork *this);

/*
 * Deinitializes the given fork object. Does nothing if no object is given.
 */
void			fork_destroy(struct s_fork *this);

/*
 * Destroys and frees the given fork object. Does nothing if no fork object is
 * given.
 */
void			fork_delete(struct s_fork *this);

#endif
