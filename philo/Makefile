# The name of the executable.
NAME = philo

# The name of the tags file.
TAGS = tags

# The source files.
SRC = ./main.c ./philosopher/philo.c ./delegate/delegate.c ./utils/ft_atoi.c     \
	  ./utils/ft_strings.c ./delegate/delegate_validation.c ./philosopher/fork.c \
	   ./philosopher/philo_run.c ./delegate/delegate_print.c                     \
	  ./delegate/delegate_simulation.c ./delegate/delegate_time.c                \
	  ./philosopher/philo_action.c ./philosopher/fork_take.c                     \
	  ./delegate/delegate_checks.c ./delegate/delegate_meals.c                   \
	  ./philosopher/philo_update_meals.c ./philosopher/philo_index.c

# The header files.
HDR = ./philosopher/philo.h ./philosopher/state.h ./delegate/delegate.h \
	  ./philosopher/fork.h ./utils/utils.h

# The object files.
OBJ = $(patsubst %.c,%.o,$(SRC))

# The flags to compile with.
CFLAGS = -Wall -Werror -Wextra -I. -Ofast

# The flags to link with.
LDFLAGS = -pthread


# Makes whatever is needed.
all: $(NAME)

# Runs the simulation with an impossible high amount of threads.
ruin: $(NAME)
	./$(NAME) 20000 800 200 200

# Runs the norm checker on the registered source files.
nor:
	norminette $(SRC) $(HDR) | grep -v "header"

# Makes whatever is needed for the executable.
$(NAME): $(OBJ) $(H_O)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

# Runs an example simulation.
run: $(NAME)
	./$(NAME) 8 800 200 200

# Compiles each file individually.
%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Creates the tags file.
$(TAGS):
	$(RM) $(TAGS)
	ctags -t -f $(TAGS) $(HDR) $(SRC)

# Removes all temporary files.
clean:
	- $(RM) $(OBJ)
	- $(RM) *~
	- find . -name \*~ -print -delete

# Removes everything created by this makefile.
fclean: clean
	- $(RM) $(NAME)

# Removes all files created by this makefile and recompiles the project.
re: fclean all

.PHONY: all nor clean fclean re nor $(TAGS)
