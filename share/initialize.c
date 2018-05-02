#include "pushswap.h"

struct s_stack   *g_a;
struct s_stack   *g_b;

void	initialize(int stack_size, char **args)
{
    g_a = (t_stack *)malloc(sizeof(t_stack));
    g_b = (t_stack *)malloc(sizeof(t_stack));
    ft_bzero(g_a, sizeof(t_stack));
    ft_bzero(g_b, sizeof(t_stack));
	while (stack_size--)
		push(g_a, ft_atoi(args[stack_size]));
}