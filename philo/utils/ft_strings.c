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

bool	ft_isnum(const char *string)
{
	size_t	i;
	bool	ret;

	if (string == NULL || string[0] == '\0')
		return (false);
	i = 0;
	ret = false;
	if (string[0] == '+' || string[0] == '-')
		i++;
	while (string[i] != '\0')
	{
		if (!ft_strchr("0123456789", string[i]))
			return (false);
		ret = true;
		i++;
	}
	return (ret);
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
