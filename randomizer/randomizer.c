/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:07:14 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/03 16:07:18 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <time.h>

static inline t_bool	is_unique(int tmp, int *arr, int counter)
{
	int					i;

	i = -1;
	while (++i < counter)
		if (arr[i] == tmp)
			return (FALSE);
	return (TRUE);
}

static inline void		fill_output(int *output, int count, int limit)
{
	int					i;
	int					tmp;

	i = 0;
	tmp = 0;
	while (i < count)
	{
		tmp = (rand() % limit) * ((rand() % 2) ? -1 : 1);
		if (is_unique(tmp, output, i))
			output[i++] = tmp;
	}
}

static inline void		print_output(int *output, int count)
{
	int					i;

	i = -1;
	while (++i < count)
		ft_printf("%d ", output[i]);
	ft_putchar('\n');
}

int						main(int ac, char **av)
{
	time_t				t;
	int					count;
	int					limit;
	int					*output;

	if (ac >= 2)
	{
		srand((unsigned)time(&t));
		count = ft_atoi(av[1]);
		output = ft_memalloc(sizeof(int) * count);
		ft_bzero(output, sizeof(int) * count);
		if (ac == 3)
			limit = ft_atoi(av[2]);
		else
			limit = count * 2;
		fill_output(output, count, limit);
		print_output(output, count);
		free(output);
	}
	return (0);
}
