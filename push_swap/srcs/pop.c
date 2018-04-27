#include "push_swap.h"

int			pop(t_stack *stack)
{
	t_list	*tmp;
	int		pop_element;

	tmp = stack->stack_content;
	pop_element = *((int *)(tmp->content));
	stack->stack_content = tmp->next;
	free(tmp->content);
	free(tmp);
	stack->size--;
	return (pop_element);
}