#include "pushswap.h"

void		swap(t_stack *stack)
{
	int		a;
	int		b;
	t_list	*items;

	items = stack->stack_content;
	if (items && items->next)
	{
		a = *((int *)(items->content));
		b = *((int *)(items->next->content));
		*((int *)(items->next->content)) = a;
		*((int *)(items->content)) = b;
	}
}