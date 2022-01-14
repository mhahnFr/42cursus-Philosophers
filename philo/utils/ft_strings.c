#include <stddef.h>

#include "utils.h"

char	*ft_strchr(const char *string, const char c)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			return ((char *) string + i);
		i++;
	}
	if (string[i] == c)
		return ((char *) string + i);
	return (NULL);
}

bool	ft_is_whitespace(const char c)
{
	return (c == '\n'
		|| c == '\t'
		|| c == '\v'
		|| c == '\b'
		|| c == '\r'
		|| c == '\f'
		|| c == '\a');
}
