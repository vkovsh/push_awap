#include "pushswap.h"

void    rev_rotate(t_stack *stack)
{
	ft_lstrev(&(stack->stack_content));
	rotate(stack);
	ft_lstrev(&(stack->stack_content));
}