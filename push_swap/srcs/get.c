#include "push_swap.h"

int			get(t_stack *stack, int i)
{
    t_list  *items;
	int		index;

	items = stack->stack_content;
	index = -1;
	while (++index < i && items)
	{
		items = items->next;
	}
	return (*((int *)(items->content)));
}