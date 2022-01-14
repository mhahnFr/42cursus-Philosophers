#include <stddef.h>

#include "utils.h"

static void	ft_assign_trick(int *sign, char **pos, bool *ret, size_t *in)
{
	*sign = 1;
	*pos = NULL;
	*ret = false;
	*in = 0;
}

int	ft_atoi(const char *string)
{
	int	ret;

	(void) ft_atoi_error(string, &ret);
	return (ret);
}

bool	ft_atoi_error(const char *string, int *i)
{
	return (ft_atoi_base(string, i, "0123456789", 10));
}

bool	ft_atoi_base(
			const char *string,
			int *i,
			const char *base,
			long base_length)
{
	int		sign;
	char	*pos;
	bool	ret;
	size_t	in;

	ft_assign_trick(&sign, &pos, &ret, &in);
	*i = 0;
	while (ft_is_whitespace(string[in]) && string[in] != '\0')
		in++;
	if (string[in] == '-' || string[in] == '+')
	{
		if (string[in] == '-')
			sign = -1;
		in++;
	}
	while (string[in] != '\0')
	{
		pos = ft_strchr(base, string[in]);
		if (pos == NULL)
			break ;
		ret = true;
		*i = (*i * base_length) + (pos - base);
		in++;
	}
	*i *= sign;
	return (ret);
}
