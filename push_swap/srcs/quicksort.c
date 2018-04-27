#include "push_swap.h"
struct s_stack   *g_a;
struct s_stack   *g_b;

static int  partition(int l, int h)
{
    int     pivot;
    int     i;
    int     j;

    pivot = get(l);
    i = l - 1;
    j = h + 1;
    while (1)
    {
        while (get(++i) < pivot && i < (int)(g_a->size) - 1);
        while (get(--j) > pivot && j > 0);
        if (i >= j)
            return (j);
        swap_i_j(i, j);
    }
    return (0);
}

void        quicksort(int l, int h)
{
    int pivot;

    pivot = partition(l, h);
    ft_printf("pivot = %d\n", pivot);
    quicksort(l, pivot);
    quicksort(pivot + 1, h);
}