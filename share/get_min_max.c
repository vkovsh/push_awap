/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:36:12 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 13:36:18 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			get_min(t_stack *s)
{
	t_list	*items;
	int		min;

	items = s->stack_content;
	min = get(s, 0);
	while (items)
	{
		if (*((int *)(items->content)) < min)
			min = *((int *)(items->content));
		items = items->next;
	}
	return (min);
}

int			get_max(t_stack *s)
{
	t_list	*items;
	int		max;

	items = s->stack_content;
	max = get(s, 0);
	while (items)
	{
		if (*((int *)(items->content)) > max)
			max = *((int *)(items->content));
		items = items->next;
	}
	return (max);
}
