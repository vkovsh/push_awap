/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:41:40 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 14:42:39 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		rotate(t_stack *stack)
{
	int		first;
	t_list	*items;

	items = stack->stack_content;
	if (!items || !(items->next))
		return ;
	first = *((int *)(items->content));
	while (items && items->next)
	{
		*((int *)(items->content)) =
			*((int *)(items->next->content));
		items = items->next;
	}
	*((int *)(items->content)) = first;
}
