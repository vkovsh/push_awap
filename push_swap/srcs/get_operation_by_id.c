#include "push_swap.h"

const char	*get_operation_by_id(t_operation operation)
{
	if (operation == sa)
		return ("sa");
	if (operation == sb)
		return ("sb");
	if (operation == ss)
		return ("ss");
	if (operation == pa)
		return ("pa");
	if (operation == pb)
		return ("pb");
	if (operation == ra)
		return ("ra");
	if (operation == rb)
		return ("rb");
	if (operation == rr)
		return ("rr");
	if (operation == rra)
		return ("rra");
	if (operation == rrb)
		return ("rrb");
	if (operation == rrr)
		return ("rrr");
	return (NULL);
}