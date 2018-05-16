/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_stack_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:45:51 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 14:45:53 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char				*trimmed_i;
	char				*trimmed_j;

	i = -1;
	while (++i < size)
	{
		j = i;
		trimmed_i = ft_strtrim(args[i]);
		if (!(is_signed_int(trimmed_i)))
			return (FALSE);
		while (++j < size)
		{
			trimmed_j = ft_strtrim(args[j]);
			if (!ft_strcmp(trimmed_i, trimmed_j))
				return (FALSE);
			ft_strdel(&trimmed_j);
		}
		ft_strdel(&trimmed_i);
	}
	return (TRUE);
}
