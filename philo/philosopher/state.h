#ifndef STATE_H
# define STATE_H

/*
 * An enumeration with the possible states a philosopher can have.
 */
enum e_state {
	DIED,
	EATING,
	SLEEPING,
	THINKING,
	STOPPED,
	UNDEFINED
};

#endif
