/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_i_j.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:45:23 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 14:45:25 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	inner_cost_one(int min)
{
	int		index;

	index = -1;
	while (++index < min)
	{
		do_op(pb);
		optimisation_condition();
	}
	if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
		do_op(ss);
	else
		do_op(sa);
	index = -1;
	while (++index < min)
	{
		do_op(pa);
		optimisation_condition();
	}
}

static void	outer_cost_one(void)
{
	do_op(rra);
	if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
		do_op(ss);
	else
		do_op(sa);
	do_op(ra);
}

static void	stabilize_general_case(int min, int inner_cost)
{
	int		index;

	index = 0;
	while (++index < inner_cost)
	{
		do_op(pa);
		optimisation_condition();
	}
	do_op(rra);
	index = -1;
	while (++index < min)
	{
		do_op(pa);
		optimisation_condition();
	}
}

static void	general_case(int min, int inner_cost)
{
	int		index;

	index = -1;
	while (++index < min)
	{
		do_op(pb);
		optimisation_condition();
	}
	do_op(ra);
	index = 0;
	while (++index < inner_cost)
	{
		do_op(pb);
		optimisation_condition();
	}
	do_op(rra);
	if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
		do_op(ss);
	else
		do_op(sa);
	do_op(ra);
	stabilize_general_case(min, inner_cost);
}

void		swap_i_j(int i, int j)
{
	int		min;
	int		max;
	int		inner_cost;
	int		outer_cost;

	if (i <= 1 && j <= 1)
	{
		if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
			do_op(ss);
		else
			do_op(sa);
	}
	else
	{
		min = (i < j) ? i : j;
		max = (i > j) ? i : j;
		if ((inner_cost = max - min) == 1)
			inner_cost_one(min);
		else if ((outer_cost = min + g_a->size - max) == 1)
			outer_cost_one();
		else
			general_case(min, inner_cost);
	}
}
