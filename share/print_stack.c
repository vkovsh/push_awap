#include "pushswap.h"

void        print_stack(t_stack *stack)
{
    t_list  *items;
    int     i;

    items = stack->stack_content;
    i = 1;
    while (items)
    {
        ft_dprintf(log_descriptor,
            "%10d%10s%10d\n", i++, "--->",
            *((int *)(items->content)));
        items = items->next;
    }

}