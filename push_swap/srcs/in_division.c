#include "push_swap.h"

int     in_division(int board, t_stack *s)
{
    int in;
    t_list *items;

    in = 0;
    items = s->stack_content;
    while (items)
    {
        if (*((int *)(items->content)) >= board)
            in++;
        items = items->next;
    }
    return (in);
}