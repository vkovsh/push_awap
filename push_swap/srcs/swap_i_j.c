#include "push_swap.h"
struct s_stack *g_a;

void	swap_i_j(int i, int j)
{
	int	min;
	int	max;
	int	inner_cost;
	int	outer_cost;
	int	index;

	if (i < 0 || j < 0 ||
		i >= (int)(g_a->size) || j >= (int)(g_a->size))
		exit(0);
	if (i == j)
		return ;
	if (i <= 1 && j <= 1)
	{
		do_op(sa);
	}
	else
	{
		min = (i < j) ? i : j;
		max = (i > j) ? i : j;
		inner_cost = max - min;
		outer_cost = min + g_a->size - max;
		if (inner_cost == 1)
		{
			index = -1;
			while (++index < min)
			{
				do_op(pb);
			}
			do_op(sa);
			index = -1;
			while (++index < min)
			{
				do_op(pa);
			}
		}
		else if (outer_cost == 1)
		{
			do_op(rra);
			do_op(sa);
			do_op(ra);
		}
		else if (inner_cost <= outer_cost)
		{
			index = -1;
			while (++index <= min)
			{
				do_op(pb);
			}
			index = 0;
			while (++index < inner_cost)
			{
				do_op(ra);
			}
			do_op(pa);
			do_op(sa);
			do_op(pb);
			index = 0;
			while (++index < inner_cost)
			{
				do_op(rra);
			}
			index = -1;
			while (++index <= min)
			{
				do_op(pa);
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
			}
		}
	}
}