#include "pushswap.h"

struct s_stack   *g_a;
struct s_stack   *g_b;

t_bool	validate_args(char **args)
{
	if (args)
		return (TRUE);
	return (FALSE);
}

void	initialize(int stack_size, char **args)
{
    g_a = (t_stack *)malloc(sizeof(t_stack));
    g_b = (t_stack *)malloc(sizeof(t_stack));
    ft_bzero(g_a, sizeof(t_stack));
    ft_bzero(g_b, sizeof(t_stack));
	if (!validate_args(args))
	{
		ft_printf("Error\n");
		exit(0);
	}
	while (stack_size--)
		push(g_a, ft_atoi(args[stack_size]));
}