#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

/*
 * Converts the given string to an integer representation. See "man 3 atoi".
 */
int		ft_atoi(const char *string);

/*
 * Converts the given string to an integer representation and stores the result
 * at the given imemory address. Returns wether the conversion was successfull.
 */
bool	ft_atoi_error(const char *string, int *i);

/*
 * Converts the given string to an integer representation using the given base
 * and stores the result at the given memory address. Returns wether the
 * conversion was successfull.
 */
bool	ft_atoi_base(
			const char *string,
			int *i,
			const char *base,
			long base_length);

/*
 * Returns a pointer to the first occurance of the given character in the given
 * string. Returns a null pointer if the given string does not contain the
 * given character.
 */
char	*ft_strchr(const char *string, const char c);

/*
 * Returns wether the given character is a whitespace.
 */
bool	ft_is_whitespace(const char c);

#endif
