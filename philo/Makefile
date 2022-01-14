# The name of the executable.
NAME = philo

# The source files.
SRC = ./main.c ./philo.c ./delegate.c ./utils/ft_atoi.c ./utils/ft_strings.c  \
	  ./delegate_validation.c

# The header files.
HDR = ./philo.h ./state.h ./delegate.h

# The header object files.
H_O = $(patsubst %.h,%.gch,$(HDR))

# The object files.
OBJ = $(patsubst %.c,%.o,$(SRC))

# The flags to compile with.
CFLAGS = -Wall -Werror -Wextra -g #-Ofast

# The flags to link with.
LDFLAGS = -I.


# Makes whatever is needed.
all: $(NAME)

# Makes whatever is needed for the executable.
$(NAME): $(OBJ) $(H_O)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

# Runs the norm checker on each registered source file.
nor:
	norminette $(SRC) $(patsubst %.c,%.h,$(SRC)) | grep :

%.gch: %.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Compiles each file individually.
%.o: %.c $(H_O)
	$(CC) $(CFLAGS) -c -o $@ $<

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

.PHONY: all nor clean fclean re
