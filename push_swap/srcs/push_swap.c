#include "push_swap.h"

struct s_stack   *g_a;
struct s_stack   *g_b;

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		initialize(ac - 1, &(av[1]));
		quicksort(0, g_a->size - 1);
	}
	else
		ft_printf("Error\n");
	return (0);
}