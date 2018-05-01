#include "pushswap.h"
struct s_stack *g_a;
struct s_stack *g_b;
int ops;

void	do_op(t_operation op)
{
	ops++;
	if (op == sa)
		swap(g_a);
	else if (op == sb)
		swap(g_b);
	else if (op == ss)
	{
		swap(g_a);
		swap(g_b);
	}
	else if (op == pa)
		push_pop(g_a, g_b);
	else if (op == pb)
		push_pop(g_b, g_a);
	else if (op == ra)
		rotate(g_a);
	else if (op == rb)
		rotate(g_b);
	else if (op == rr)
	{
		rotate(g_a);
		rotate(g_b);
	}
	else if (op == rra)
		rev_rotate(g_a);
	else if (op == rrb)
		rev_rotate(g_b);
	else if (op == rrr)
	{
		rev_rotate(g_a);
		rev_rotate(g_b);
	}
	//ft_printf("-------------------\n");
	ft_printf("%s\n", get_operation_by_id(op));
	/*ft_printf("%s\n", "Stack a");
	print_stack(g_a);
	ft_printf("%s\n", "Stack b");
	print_stack(g_b);
	ft_printf("-------------------\n");*/
}