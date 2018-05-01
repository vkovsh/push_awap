#include "pushswap.h"

struct s_stack   *g_a;
struct s_stack   *g_b;
int	ops;

void	swap_unit_test(void)
{
	int i;
	int j;
	int	sum;
	int swap_num;

	i = -1;
	sum = 0;
	swap_num = 0;
	while (++i < (int)(g_a->size))
	{
		j = -1;
		while (++j < (int)(g_a->size))
		{
			if (i != j)
			{
				ops = 0;
				swap_num++; 
				ft_printf("Swaping a[%d] - a[%d]\n", i, j);
				ft_printf("-------------------\n");
				swap_i_j(i, j);
				sum += ops;
				ft_printf("ops = %d\n", ops);
				ft_printf("-------------------\n");
			}
		}
	}
	ft_printf("SUM = %d\n", sum);
	ft_printf("average = %d\n", sum / swap_num);
}

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

void	average_division(int aver)
{
	int		pivot;
	t_bool	pivot_inited;

	pivot_inited = FALSE;
	while (TRUE)
	{
		if(get(g_a, 0) < aver)
		{
			do_op(pb);
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

void	arbitrary_division(void)
{
	int		pivot;

	pivot = get(g_a, g_a->size - 1);
	while (TRUE)
	{
		if(get(g_a, 0) < pivot)
			do_op(pb);
		else
		{
			if (get(g_a, 0) == pivot)
				break ;
			do_op(ra);
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
	while (in_division(--max, s) < number);
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
				while (g_a->size >= 5)
					average_division(get_optimal_division(g_a));
				quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
				while (g_b->size >= 6)
				{
					int mawaru = 0;
					int division = get_fixed_division(g_b, 6);
					//ft_printf("%d\n", division);
					int k = 6;
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