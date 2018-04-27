#include "push_swap.h"

void    push(t_stack *stack, int element)
{
    t_list  *new_elem;

    new_elem = ft_lstnew(&element, sizeof(int));
    ft_lstadd(&(stack->stack_content), new_elem);
    stack->size++;
} 