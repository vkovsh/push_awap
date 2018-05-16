/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:40:11 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 15:40:13 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int g_descriptor;

static inline void	solve(void)
{
	left_joggle(g_a->size - 1);
	right_joggle(g_b->size - 1);
	while (g_b->size)
	{
		do_op(pa);
		quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
	}
	destruct(g_a);
	destruct(g_b);
}

int					main(int ac, char **av)
{
	if (ac > 1)
	{
		if (validate_stack_args(ac - 1, &(av[1])))
		{
			initialize(ac - 1, &(av[1]));
			g_descriptor = 1;
			if (g_a->size <= 10)
				quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
			else
				solve();
		}
		else
			ft_printf("Error\n");
	}
	else
		ft_printf("Error\n");
	return (0);
}
