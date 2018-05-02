#include "pushswap.h"

static inline t_bool	in_limits(char *str)
{
	if (ft_isdigit(*str))
	{
		if (ft_strcmp("2147483647", str) < 0)
			return (FALSE);
	}
	else if (*str == '-')
	{
		if (ft_strcmp("−2147483648", str) < 0)
			return (FALSE);
	}
	else if (*str == '+')
	{
		if (ft_strcmp("+2147483647", str) < 0)
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}

static inline t_bool	is_signed_int(char *str)
{
	size_t				length;

	length = ft_strlen(str);
	if (length > 11)
		return (FALSE);
	if (length == 10 || length == 11)
	{
		if (!in_limits(str))
			return (FALSE);
	}
	else
	{
		if (*str == '-' || *str == '+')
			str++;
		if (!ft_aredigits(str))
			return (FALSE);
	}
	return (TRUE);
}

t_bool					validate_stack_args(int size, char **args)
{
	int					i;
	int					j;

	i = -1;
	while (++i < size)
	{
		j = i;
		if (!(is_signed_int(args[i])))
			return (FALSE);
		while (++j < size)
		{
			if (!ft_strcmp(args[i], args[j]))
				return (FALSE);
		}
	}
	return (TRUE);
}