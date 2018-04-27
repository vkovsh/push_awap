#include "push_swap.h"

struct s_stack *g_a;

int			get(int i)
{
    t_list  *items;
	int		index;

	items = g_a->stack_content;
	index = -1;
	while (++index < i && items)
	{
		items = items->next;
	}
	return (*((int *)(items->content)));
}