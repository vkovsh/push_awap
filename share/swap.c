/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:43:29 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 14:43:33 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		swap(t_stack *stack)
{
	int		a;
	int		b;
	t_list	*items;

	items = stack->stack_content;
	if (items && items->next)
	{
		a = *((int *)(items->content));
		b = *((int *)(items->next->content));
		*((int *)(items->next->content)) = a;
		*((int *)(items->content)) = b;
	}
}
