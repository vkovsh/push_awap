/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_descending.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:46:48 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 13:46:52 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bool		is_descending(t_stack *stack)
{
	t_list	*items;
	int		a;
	int		b;

	if (!(items = stack->stack_content)
		|| !(items->next))
		return (TRUE);
	while (items->next)
	{
		a = *((int *)(items->content));
		b = *((int *)(items->next->content));
		if (!(a > b))
			return (FALSE);
		items = items->next;
	}
	return (TRUE);
}
