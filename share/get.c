/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:34:20 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 13:34:28 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			get(t_stack *stack, int i)
{
	t_list	*items;
	int		index;

	items = stack->stack_content;
	index = -1;
	while (++index < i && items)
	{
		items = items->next;
	}
	return (*((int *)(items->content)));
}
