#include "pushswap.h"

void        print_stack(t_stack *stack)
{
    t_list  *items;
    int     i;

    items = stack->stack_content;
    i = 0;
    while (items)
    {
        ft_printf("#%d: %d\n", i, *((int *)(items->content)));
        i++;
        items = items->next;
    }

}