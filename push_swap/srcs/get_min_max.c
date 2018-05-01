#include "push_swap.h"

int         get_min(t_stack *s)
{
    t_list  *items;
    int     min;

    items = s->stack_content;
    min = get(s, 0);
    while (items)
    {
        if (*((int *)(items->content)) < min)
            min = *((int *)(items->content));
        items = items->next;
    }
    return (min);
}

int         get_max(t_stack *s)
{
    t_list  *items;
    int     max;

    items = s->stack_content;
    max = get(s, 0);
    while (items)
    {
        if (*((int *)(items->content)) > max)
            max = *((int *)(items->content));
        items = items->next;
    }
    return (max);
}