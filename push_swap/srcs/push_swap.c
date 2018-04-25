#include "push_swap.h"

struct s_stack   *g_a;
struct s_stack   *g_b;

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		initialize(ac - 1, &(av[1]));
		int i = -1;
		rev_rotate(g_a);
		while (++i < ac - 1)
		{
			ft_printf("%d\n", pop(g_a));
		}
	}
	else
		ft_printf("Error\n");
	return (0);
}