#include "push_swap.h"

t_bool		is_ascending(t_stack *stack)
{
	t_list	*items;
	int		a;
	int		b;

	if (!(items = stack->stack_content)
		|| !(items->next))
		return (TRUE);
	while (items->next)
	{
		a = *((int *)(items->content));
		b = *((int *)(items->next->content));
		if (!(a < b))
			return (FALSE);
		items = items->next;
	}
	return (TRUE);
}