/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:26:43 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/01 18:26:50 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_op(t_operation op)
{
	if (op == sa)
		swap(g_a);
	else if (op == sb)
		swap(g_b);
	else if (op == ss)
	{
		SWAP_BOTH();
	}
	else if (op == pa)
		push_pop(g_a, g_b);
	else if (op == pb)
		push_pop(g_b, g_a);
	else if (op == ra)
		rotate(g_a);
	else if (op == rb)
		rotate(g_b);
	else if (op == rr)
	{
		ROTATE_BOTH();
	}
	else if (op == rra)
		rev_rotate(g_a);
	else if (op == rrb)
		rev_rotate(g_b);
	else if (op == rrr)
	{
		REV_ROTATE_BOTH();
	}
	ft_printf("%s\n", get_operation_by_id(op));
	print_stack(g_a);
}
