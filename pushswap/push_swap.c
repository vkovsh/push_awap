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
	int		pivot;
	t_bool	pivot_inited;
	int		mawaru;

	pivot_inited = FALSE;
	mawaru = 0;
	while (count)
	{
		if(get(g_a, 0) <= aver)
		{
			do_op(pb);
			/*if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
				(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
				do_op(ss);
			else if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
				do_op(sb);
			else if (g_a->size >= 2 && get(g_a, 0) > get(g_a, 1))
				do_op(sa);*/
			count--;
		}
		else
		{
			if (pivot_inited)
			{
				if (get(g_a, 0) == pivot)
					break ;
			}
			else
			{
				pivot = get(g_a, 0);
				pivot_inited = TRUE;
			}
			do_op(ra);
			mawaru++;
		}
	}
	//ft_printf("mawaru = %d\n", mawaru);
	if (mawaru <= (int)(g_a->size / 3))
	{
		//ft_printf("mawaru");
		while (mawaru--)
			do_op(rra);
	}
}

void	average_division_b(int aver, int count)
{
	int		pivot;
	t_bool	pivot_inited;
	int		mawaru;

	mawaru = 0;
	pivot_inited = FALSE;
	while (count)
	{
		if(get(g_b, 0) >= aver)
		{
			do_op(pa);
			/*if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
				(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
				do_op(ss);
			else if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
				do_op(sb);
			else if (g_a->size >= 2 && get(g_a, 0) > get(g_a, 1))
				do_op(sa);*/
			count--;
		}
		else
		{
			if (pivot_inited)
			{
				if (get(g_b, 0) == pivot)
					break ;
			}
			else
			{
				pivot = get(g_b, 0);
				pivot_inited = TRUE;
			}
			do_op(rb);
			mawaru++;
		}
	}
	if (mawaru <= (int)(g_b->size) / 3)
	{
		//ft_printf("mawaru");
		while (mawaru--)
			do_op(rrb);
	}
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
	while (in_division(max, s) <= number)
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
	if (!throw_count)
		return ;
	if (throw_count < 3)
	{
		average_division_b(get_fixed_division(g_b, throw_count), throw_count);
		quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
	}
	else
	{
		average_division_b(get_fixed_division(g_b, throw_count / 2), throw_count / 2);
		left_joggle(throw_count / 2);
		right_joggle(throw_count / 2);
	}
}

void	left_joggle(int throw_count)
{
	if (!throw_count)
		return ;
	if (throw_count < 3)
	{
		quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
	}
	else
	{
		average_division_a(get_fixed_division(g_a, g_a->size - throw_count / 2), throw_count / 2);
		left_joggle(throw_count / 2);
		right_joggle(throw_count / 2);
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
			if (g_a->size <= 20)
				quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
			else
			{
				left_joggle(g_a->size);
				ft_printf("A\n");
				print_stack(g_a);
				ft_printf("B\n");
				print_stack(g_b);
				ft_printf("CHAOS A = %d\n", chaos_metric(g_a));
				ft_printf("CHAOS B = %d\n", chaos_metric(g_b));
				
				
				//ft_printf("ddd = %d\n", get_fixed_division(g_a, g_a->size - size / 4));
				/*
				average_division_a(get_fixed_division(g_a, 2 * g_a->size / 3), g_a->size / 3);
				while (g_b->size >= 10)
					average_division_b(get_fixed_division(g_b, g_b->size / 3), g_b->size / 3);
				while (g_a->size >= 10)
					average_division_a(get_fixed_division(g_a, 2 * g_a->size / 3), g_a->size / 3);
				average_division_a(get_fixed_division(g_a, 5), 5);
				quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
				while (g_b->size >= 3)
				{
					int mawaru = 0;
					int division = get_fixed_division(g_b, 3);
					int k = 3;
					while (k)
					{
						if (get(g_b, 0) >= division)
						{
							do_op(pa);
							quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
							if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
								(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
								do_op(ss);
							else if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
								do_op(sb);
							else if (g_a->size >= 2 && get(g_a, 0) > get(g_a, 1))
								do_op(sa);
							k--;
						}
						else
						{
							if (get(g_b, 1) >= division)
							{
								if (g_a->size >= 2 && get(g_a, 0) > get(g_a, 1))
									do_op(ss);
								else
									do_op(sb);
								do_op(pa);
								k--;
							}
							else
							{
								mawaru++;
								do_op(rb);
							}
						}
					}
					
					while (mawaru--)
					{
						do_op(rrb);
						if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
							(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
							do_op(ss);
						else if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
							do_op(sb);
						else if (g_a->size >= 2 && get(g_a, 0) > get(g_a, 1))
							do_op(sa);
					}
					
				}
				while (g_b->size)
					do_op(pa);
				quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
			*/
			}
			
		}
		else
			ft_printf("Error\n");
	}
	else
		ft_printf("Error\n");
	return (0);
}