#include "pushswap.h"

void        print_stack(t_stack *stack)
{
    t_list  *items;
    int     i;

    items = stack->stack_content;
    i = 0;
    while (items)
    {
        ft_printf("%d%[*]s%[*]{*}d\n", i, 0x0f00f0,
            "   --->   ",
            0xff0000, 0x00ff00, *((int *)(items->content)));
        i++;
        items = items->next;
    }

}