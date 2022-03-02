# Welcome to 42cursus-Philosophers!
This repository contains a project of the [42 school]. The goal of this project
is to write a small application simulating the famous
[Dining philosophers problem]. It has to be simulated with one thread
representing one philosopher.

## Approach
My approach is object-orientied: the application has a delegate object
containing all informations such as the timeout values, which also holds an
array of philosopher objects. Each philosopher object contains the thread it is
running in as well as a fork object. A fork object consists of the status of
the fork and a mutex in order to protect the access to it.

After parsing the arguments, all threads are created and started. This happens
inside of a mutex in order to prevent the threads from starting the simulation.
Once all threads have been created, the simulation starts. Before something is
printed, it is checked wether the simulation is still ongoing. If that is not
the case, the thread will terminate.

The main thread acts as a supervisor: if the number of times each philosopher
has to eat is set, the value of full philosophers in the delegate object is
observed. Once all philosophers are full, the flag for the threads to stop is
set, and all threads are joined by the main thread. If the meal count is not
set, all threads are directly joined by the main thread.

Upon termination of all philosopher threads, the application exites.

## Usage
Launch the executable with 4 or 5 arguments: ``./philo 8 410 200 200 5``.

The arguments are described as follows:
- ``8`` (``count``): The number of philosophers to be simulated.
- ``410`` (``time_to_die``): The time after which a philosopher dies, if he was
not able to eat in the meantime.
- ``200`` (``time_to_eat``): The time each philosopher needs to eat.
- ``200`` (``time_to_sleep``): The time each philosopher is sleeping after his
meal.
- ``5`` (``meal_count``): The number of times each philosopher has to eat. Once
all philosophers have eaten that amount of times, the simulation stops. If this
argument is not set, the simulaion will stop upon the death of a philosopher.

All times are treated as milliseconds.

### Final notes
This repository contains the solutions I submitted in the [42 school]. It will
not be developed further.

© Copyright 2022 [mhahnFr](https://www.github.com/mhahnFr)

[Dining philosophers problem]: https://en.wikipedia.org/wiki/Dining_philosophers_problem
[42 school]: https://www.42heilbronn.de/learncoderepeat
