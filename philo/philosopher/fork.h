#ifndef FORK_H
# define FORK_H

# include <stdbool.h>
# include <pthread.h>

/*
 * Represents a fork. Includes a mutex to prevent being accessed by muliple
 * threads.
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
 * Returns wether the given fork is taken. Locks its mutex to retrieve the data.
 */
bool			fork_is_taken(struct s_fork *this);

/*
 * Attempts to take the given fork. Returns true on success, false if the fork is already taken.
 */
bool			fork_take(struct s_fork *this);

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
