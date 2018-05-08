#include "pushswap.h"

static void	inner_cost_one(int min)
{
	int	index;

	if (min < (int)(g_a->size) / 2 + 1)
	{
		index = -1;
		while (++index < min)
		{
			do_op(pb);
			if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
					(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
					do_op(ss);
		}
		if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
			do_op(ss);
		else
			do_op(sa);
		index = -1;
		while (++index < min)
		{
			do_op(pa);
			if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
				(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
				do_op(ss);
		}
	}
	else
	{
		index = -1;
		while (++index < (int)(g_a->size) - min)
			do_op(rra);
		do_op(sa);
		index = -1;
		while (++index < (int)(g_a->size) - min)
			do_op(ra);
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

void	swap_i_j(int i, int j)
{
	int	min;
	int	max;
	int	inner_cost;
	int	outer_cost;
	int	index;

	//ft_printf("swap: %d %d\n", i , j);
	if (i == j)
		return ;
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
		else if (inner_cost < outer_cost)
		{
			index = -1;
			while (++index < min)
			{
				do_op(pb);
				if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
					(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
					do_op(ss);
			}
			do_op(ra);
			index = 0;
			while (++index < inner_cost)
			{
				do_op(pb);
				if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
					(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
					do_op(ss);
			}
			do_op(rra);
			if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
				do_op(ss);
			else
				do_op(sa);
			do_op(ra);
			index = 0;
			while (++index < inner_cost)
			{
				do_op(pa);
				if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
					(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
					do_op(ss);
			}
			do_op(rra);
			index = -1;
			while (++index < min)
			{
				do_op(pa);
				if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
					(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
					do_op(ss);
			}
		}
		else
		{
			int back_items = g_a->size - max - 1;
			int forward_items = min;
			index = -1;
			while (++index < forward_items)
			{
				do_op(pb);
				if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
					(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
					do_op(ss);
			}
			index = -1;
			while (++index < back_items)
			{
				do_op(rra);
				do_op(pb);
			}
			do_op(rra);
			do_op(sa);
			do_op(ra);
			index = -1;
			while (++index < back_items)
			{
				do_op(pa);
				do_op(ra);
			}
			index = -1;
			while (++index < forward_items)
			{
				do_op(pa);
				if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
					(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
					do_op(ss);
			}
		}
	}
	//ft_printf("end swap: %d %d\n", i, j);
}