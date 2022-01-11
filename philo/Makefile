# The name of the executable.
NAME = philo

# The source files.
SRC = 

# The object files.
OBJ = $(patsubst %.o,%.c,$(SRC))

# The flags to compile with.
CFLAGS = -Wall -Werror -Wextra -g #-Ofast

# The flags to link with.
LDFLAGS = 


# Makes whatever is needed.
all: $(NAME)

# Makes whatever is needed for the executable.
$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

# Runs the norm checker on each registered source file.
nor:
	norminette $(SRC) $(patsubst %.c,%.h,$(SRC)) | grep :

# Compiles each file individually.
%.o: %.c
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
