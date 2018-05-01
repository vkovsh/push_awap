#include "push_swap.h"

static void	inner_cost_one(int min)
{
	int	index;

	if (min < (int)(g_b->size) / 2 + 1)
	{
		index = -1;
		while (++index < min)
		{
			do_op(pa);
			if (g_a->size >= 2 && get(g_a, 0) < get(g_a, 1))
				do_op(sa);
		}
		if (g_a->size >= 2 && get(g_a, 0) < get(g_a, 1))
			do_op(ss);
		else
			do_op(sb);
		index = -1;
		while (++index < min)
		{
			do_op(pb);
			if (g_b->size >= 2 && get(g_b, 0) > get(g_b, 1))
				do_op(sb);
		}
	}
	else
	{
		index = -1;
		while (++index < (int)(g_b->size) - min)
			do_op(rrb);
		do_op(sb);
		index = -1;
		while (++index < (int)(g_b->size) - min)
			do_op(rb);
	}
}

static void	outer_cost_one(void)
{
	do_op(rrb);
	do_op(sb);
	do_op(rb);
}

void	swap_i_j_in_b(int i, int j)
{
	int	min;
	int	max;
	int	inner_cost;
	int	outer_cost;
	int	index;

	if (i == j)
		return ;
	if (i <= 1 && j <= 1)
		do_op(sb);
	else
	{
		min = (i < j) ? i : j;
		max = (i > j) ? i : j;
		if ((inner_cost = max - min) == 1)
			inner_cost_one(min);
		else if ((outer_cost = min + g_b->size - max) == 1)
			outer_cost_one();
		else if (inner_cost < outer_cost)
		{
			index = -1;
			while (++index < min)
			{
				do_op(pa);
				if (g_a->size >= 2 && get(g_a, 0) < get(g_a, 1))
					do_op(sa);
			}
			do_op(rb);
			index = 0;
			while (++index < inner_cost)
			{
				do_op(pa);
				if (g_a->size >= 2 && get(g_a, 0) < get(g_a, 1))
					do_op(sa);
			}
			do_op(rrb);
			if (g_a->size >= 2 && get(g_a, 0) < get(g_a, 1))
				do_op(ss);
			else
				do_op(sa);
			do_op(rb);
			index = 0;
			while (++index < inner_cost)
			{
				do_op(pb);
				if (g_b->size >= 2 && get(g_b, 0) > get(g_b, 1))
					do_op(sb);
			}
			do_op(rrb);
			index = -1;
			while (++index < min)
			{
				do_op(pb);
				if (g_b->size >= 2 && get(g_b, 0) > get(g_b, 1))
					do_op(sb);
			}
		}
		else
		{
			int back_items = g_b->size - max - 1;
			int forward_items = min;
			index = -1;
			while (++index < forward_items)
			{
				do_op(pa);
				if (g_a->size >= 2 && get(g_a, 0) < get(g_a, 1))
					do_op(sa);
			}
			index = -1;
			while (++index < back_items)
			{
				do_op(rrb);
				do_op(pa);
			}
			do_op(rrb);
			do_op(sb);
			do_op(rb);
			index = -1;
			while (++index < back_items)
			{
				do_op(pb);
				do_op(rb);
			}
			index = -1;
			while (++index < forward_items)
			{
				do_op(pb);
				if (g_b->size >= 2 && get(g_b, 0) > get(g_b, 1))
					do_op(sb);
			}
		}
	}
}