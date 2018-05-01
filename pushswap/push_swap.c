#include "pushswap.h"

struct s_stack   *g_a;
struct s_stack   *g_b;
int	ops;

t_bool	is_signed_decimal(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_aredigits(str))
		return (FALSE);
	return (TRUE);
}

t_bool	validate_stack_args(int size, char **args)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		if (!(is_signed_decimal(args[i])))
			return (FALSE);
		while (++j < size)
		{
			if (!ft_strcmp(args[i], args[j]))
				return (FALSE);
		}
	}
	return (TRUE);
}

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

void	average_division_a(int aver)
{
	int		pivot;
	t_bool	pivot_inited;

	pivot_inited = FALSE;
	while (TRUE)
	{
		if(get(g_a, 0) < aver)
		{
			do_op(pb);
			/*if ((g_b->size >= 2 && get(g_b, 0) < get(g_b, 1)) &&
				(g_a->size >= 2 && get(g_a, 0) > get(g_a, 1)))
				do_op(ss);
			else if (g_b->size >= 2 && get(g_b, 0) < get(g_b, 1))
				do_op(sb);
			else if (g_a->size >= 2 && get(g_a, 0) > get(g_a, 1))
				do_op(sa);*/
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
		}
	}
}

void	average_division_b(int aver)
{
	int		pivot;
	t_bool	pivot_inited;

	pivot_inited = FALSE;
	while (TRUE)
	{
		if(get(g_b, 0) > aver)
		{
			do_op(pa);
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
		}
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
	while (in_division(--max, s) < number)
	{
		continue ;
	}
	return (max);
}

int		main(int ac, char **av)
{

	if (ac > 1)
	{
		if (validate_stack_args(ac - 1, &(av[1])))
		{
			initialize(ac - 1, &(av[1]));
			if (g_a->size <= 20)
				quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
			else
			{
				average_division_a(get_fixed_division(g_a, 2 * g_a->size / 3));
				while (g_b->size >= 10)
					average_division_b(get_fixed_division(g_b, g_b->size / 3));
				while (g_a->size >= 10)
					average_division_a(get_fixed_division(g_a, 2 * g_a->size / 3));
				quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
				while (g_b->size >= 4)
				{
					int mawaru = 0;
					int division = get_fixed_division(g_b, 4);
					int k = 4;
					while (k)
					{
						if (get(g_b, 0) >= division)
						{
							do_op(pa);
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
					}
					quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
				}
				while (g_b->size)
					do_op(pa);
				quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
				/*
				average_division_a(get_optimal_division(g_a));
				while (g_b->size >= 4)
					average_division_b(get_optimal_division(g_b));
				while (g_a->size >= 4)
					average_division_a(get_optimal_division(g_a));
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
							k--;
							if (g_b->size >= 2 && get(g_b, 1) > get(g_b, 0))
								do_op(sb);
						}
						else
						{
							mawaru++;
							do_op(rb);
						}
					}
					while (mawaru--)
						do_op(rrb);
					quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
				}
				while (g_b->size)
					do_op(pa);
				quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
				*/
			}
			if (is_ascending(g_a))
				ft_printf("OK\n");
			else
				ft_printf("Error\n");
			
		}
		else
			ft_printf("Error\n");
	}
	else
		ft_printf("Error\n");
	return (0);
}