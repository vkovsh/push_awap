/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average_division.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:30:46 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 15:30:48 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	stabilize_a(void)
{
	if (g_a->mawaru <= (int)(g_a->size / 3))
	{
		while (g_a->mawaru)
		{
			(g_a->mawaru)--;
			do_op(rra);
		}
	}
	else
		g_a->mawaru = 0;
}

static void	stabilize_b(void)
{
	if (g_b->mawaru <= (int)(g_b->size) / 3)
	{
		while (g_b->mawaru)
		{
			(g_b->mawaru)--;
			do_op(rrb);
		}
	}
	else
		g_b->mawaru = 0;
}

void		average_division_a(int aver, int count)
{
	while (count)
	{
		if (get(g_a, 0) <= aver)
		{
			do_op(pb);
			optimisation_condition();
			count--;
		}
		else
		{
			do_op(ra);
			(g_a->mawaru)++;
		}
	}
	if (g_a->size && get(g_a, 0) <= aver)
		do_op(pb);
	if (g_a->size >= 2 && get(g_a, 1) <= aver)
	{
		do_op(ra);
		(g_a->mawaru)++;
		do_op(pb);
		optimisation_condition();
	}
	stabilize_a();
}

void		average_division_b(int aver, int count)
{
	while (count)
	{
		if (get(g_b, 0) >= aver)
		{
			do_op(pa);
			optimisation_condition();
			count--;
		}
		else
		{
			do_op(rb);
			(g_b->mawaru)++;
		}
	}
	if (g_b->size && get(g_b, 0) >= aver)
		do_op(pa);
	if (g_b->size >= 2 && get(g_b, 1) >= aver)
	{
		do_op(rb);
		(g_b->mawaru)++;
		do_op(pa);
		optimisation_condition();
	}
	stabilize_b();
}
