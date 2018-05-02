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

int log_descriptor;

static inline void	swap_both(void)
{
	swap(g_a);
	swap(g_b);
}

static inline void	rotate_both(void)
{
	rotate(g_a);
	rotate(g_b);
}

static inline void	rev_rotate_both(void)
{
	rev_rotate(g_a);
	rev_rotate(g_b);
}

void				do_op(t_operation op)
{
	if (op == sa)
		swap(g_a);
	else if (op == sb)
		swap(g_b);
	else if (op == ss)
		swap_both();
	else if (op == pa)
		push_pop(g_a, g_b);
	else if (op == pb)
		push_pop(g_b, g_a);
	else if (op == ra)
		rotate(g_a);
	else if (op == rb)
		rotate(g_b);
	else if (op == rr)
		rotate_both();
	else if (op == rra)
		rev_rotate(g_a);
	else if (op == rrb)
		rev_rotate(g_b);
	else if (op == rrr)
		rev_rotate_both();
	ft_dprintf(log_descriptor, "%s\n", get_operation_by_id(op));
}
