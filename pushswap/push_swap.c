#include "pushswap.h"

int log_descriptor;

int		get_average(t_stack *s)
{
	int	size;
	int	sum;
	t_list	*items;

	size = s->size;
	items = s->stack_content;
	if (!items)
		return (0);
	sum = 0;
	while (items)
	{
		sum += *((int *)(items->content));
		items = items->next;
	}
	return (sum / size);
}

void	average_division_a(int aver, int count)
{
	while (count)
	{
		//ft_printf("%10d:\n", get(g_a, 0));
		if(get(g_a, 0) <= aver)
		{
			do_op(pb);
			if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
				(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
				do_op(ss);
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
		if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
			(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
			do_op(ss);
	}
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

void	average_division_b(int aver, int count)
{
	while (count)
	{
		//ft_printf("%10d:\n", get(g_b, 0));
		if(get(g_b, 0) >= aver)
		{
			do_op(pa);
			if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
				(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
				do_op(ss);
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
		if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
			(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
			do_op(ss);
	}
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

int		get_optimal_division(t_stack *s)
{
	int	aver;
	int	min;
	int	max;
	int	half;

	aver = get_average(s);
	min = get_min(s);
	max = get_max(s);
	half = (int)(s->size) / 2;
	if ((aver - min > max - aver))
	{
		while (in_division(--max, s) != half);
		return (max);
	}
	else
	{
		while (in_division(++min, s) != half);
		return (min);
	}
	return (aver);
}

int		get_fixed_division(t_stack *s, int number)
{
	int	max;

	max = get_max(s);
	while (in_division(max, s) < number)
	{
		max--;
	}
	while (!is_exist(s, max))
	{
		max--;
	}
	return (max);
}

int			chaos_metric(t_stack *s)
{
	int		chaos;
	t_list	*items;

	chaos = 0;
	if (s->size == 0 || s->size == 1)
		return (chaos);
	items = s->stack_content;
	while (items->next)
	{
		if (*((int *)(items->content)) >
			*((int *)(items->next->content)))
			chaos++;
		items = items->next;
	}
	return (chaos);
}

void	right_joggle(int throw_count)
{
	/*ft_printf("RIGHT = %d\n", throw_count);
	ft_printf("MEDIANA = %d\n", get_fixed_division(g_b, throw_count / 2));
	ft_printf("A\n");
	print_stack(g_a);
	ft_printf("B\n");
	print_stack(g_b);*/
	if (!throw_count)
		return ;
	if (throw_count > (int)(g_b->size))
		throw_count = (int)(g_b->size);
	if (throw_count <= 3)
	{
		average_division_b(get_fixed_division(g_b, throw_count), throw_count);
		quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
	}
	else
	{
		int half_max;
		half_max = throw_count / 2;
		average_division_b(get_fixed_division(g_b, half_max), half_max);
		left_joggle(half_max);
		right_joggle(half_max);
	}
}

void	left_joggle(int throw_count)
{
	/*ft_printf("LEFT = %d\n", throw_count);
	ft_printf("MEDIANA = %d\n", get_fixed_division(g_a, g_a->size - throw_count / 2));
	ft_printf("A\n");
	print_stack(g_a);
	ft_printf("B\n");
	print_stack(g_b);*/
	if (!throw_count)
		return ;
	if (throw_count > (int)(g_a->size))
		throw_count = (int)(g_a->size);
	if (throw_count <= 3)
	{
		quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
	}
	else
	{
		int half_max;
		half_max = throw_count / 2;
		average_division_a(get_fixed_division(g_a, g_a->size - half_max), half_max);
		left_joggle(half_max);
		right_joggle(half_max);
	}
}

int		main(int ac, char **av)
{

	if (ac > 1)
	{
		if (validate_stack_args(ac - 1, &(av[1])))
		{
			log_descriptor = 1;
			initialize(ac - 1, &(av[1]));
			if (g_a->size <= 10)
			{
				quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
			}
			else
			{
				left_joggle(g_a->size);
				right_joggle(g_b->size);
				while (g_b->size)
				{
					do_op(pa);
					quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
				}
				ft_printf("A\n");
				print_stack(g_a);
				ft_printf("B\n");
				print_stack(g_b);
				ft_printf("CHAOS A = %d\n", chaos_metric(g_a));
				ft_printf("CHAOS B = %d\n", chaos_metric(g_b));
			}
			
		}
		else
			ft_printf("Error\n");
	}
	else
		ft_printf("Error\n");
	return (0);
}