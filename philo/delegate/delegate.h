#ifndef DELEGATE_H
# define DELEGATE_H

# include <stddef.h>
# include <stdbool.h>
# include <sys/time.h>

# include "philosopher/philo.h"

/*
 * A function that can be used to start a new thread.
 */
typedef void	*(*t_thread_run)(void *);

/*
 * A structure with the parameters of the simulation. Contains the philosophers
 * themselves as well as their count and the timeout values.
 */
struct s_delegate {
	volatile int			time_to_sleep;
	volatile int			time_to_eat;
	volatile int			time_to_die;
	volatile int			meal_count;
	volatile bool			meal_count_set;
	volatile struct timeval	start_time;
	pthread_mutex_t			print_mutex;
	pthread_mutex_t			simulation_state_mutex;
	int						philo_count;
	bool					simulation_running;
	struct s_philo			philosophers[];
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
void				delegate_stop_simulation(struct s_delegate *this);

/*
 * Marks the simulation with the given flag.
 */
void				delegate_mark_simulation(
						struct s_delegate *this,
						bool running);

/*
 * Returns wether the simulation is still running.
 */
bool				delegate_simulation_ongoing(struct s_delegate *this);

/*
 * Returns the number of milliseconds that have passed since the beginning of
 * the simulation.
 */
int					delegate_get_time_stamp(struct s_delegate *this);

/*
 * Returns the difference between the two given time stamps in milliseconds.
 */
int					delegate_get_time_diff(
						struct timeval *t1,
						struct timeval *t2);
/*
 * Prints the given string on the standard output. Additionally, the current
 * timestamp and the index of the philosopher are printed.
 */
void				delegate_print(
						struct s_delegate *this,
						size_t philo_index,
						char *what);

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
