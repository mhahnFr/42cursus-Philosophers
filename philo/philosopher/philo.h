#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# include "state.h"
# include "fork.h"

struct	s_delegate;

/*
 * Represents a philosopher. Contains the index of that specific philosopher,
 * its state and an indicator wether he has died.
 */
struct s_philo {
	size_t				index;
	pthread_t			thread;
	struct s_fork		fork;
	struct s_delegate	*delegate;
	long				last_eat_time;
	bool				has_died;
	int					meals;
	enum e_state		state;
};

/*
 * Allocates a new philosopher object. Returns either the newly allocated
 * object or null if the allocation failed.
 */
struct s_philo	*philo_new(size_t index, struct s_delegate *delegate);

/*
 * Initializes the given philosopher object. Does nothing if no object is
 * given.
 */
void			philo_create(
					struct s_philo *this,
					size_t index,
					struct s_delegate *delegate);

/*
 * Starts simulating the given philosopher.
 */
void			philo_run(struct s_philo *this);

/*
 * Performs the indicated action on the given philosopher object. Returns the
 * next action the philosopher will have to do. Blocks the current thread until
 * the philosopher has performed the given action or until he has died.
 */
enum e_state	philo_do_or_die(
					struct s_philo *this,
					enum e_state action);

/*
 * Simulates the given philosopher being in the state of sleep. Returns the new
 * state afterwards. Blocks until either the given philosopher has died or it
 * finished sleeping.
 */
enum e_state	philo_sleep_or_die(struct s_philo *this, int time);

/*
 * Simulates the given philosopher being in the state eating. Blocks until the
 * philosopher died or has finished eating. Returns the new state of the
 * philosopher.
 */
enum e_state	philo_eat(struct s_philo *this, int time);

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
