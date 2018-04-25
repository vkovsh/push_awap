#include "push_swap.h"

void	push_pop(t_stack *in, t_stack *out)
{
	if (!is_empty(out))
		push(in, pop(out));
}