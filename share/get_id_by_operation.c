/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id_by_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:22:13 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/01 12:22:15 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_operation		get_id_by_operation(const char *op_name)
{
    if (!ft_strcmp("sa", op_name))
		return (sa);
	else if (!ft_strcmp("sb", op_name))
		return (sb);
	else if (!ft_strcmp("ss", op_name))
		return (ss);
	else if (!ft_strcmp("pa", op_name))
		return (pa);
	else if (!ft_strcmp("pb", op_name))
		return (pb);
	else if (!ft_strcmp("ra", op_name))
		return (ra);
	else if (!ft_strcmp("rb", op_name))
		return (rb);
	else if (!ft_strcmp("rr", op_name))
		return (rr);
	else if (!ft_strcmp("rra", op_name))
		return (rra);
	else if (!ft_strcmp("rrb", op_name))
		return (rrb);
	else if (!ft_strcmp("rrr", op_name))
		return (rrr);
	return (WRONG_ID);
}
