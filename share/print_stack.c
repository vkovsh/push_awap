/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:49:38 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 13:50:44 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		print_stack(t_stack *stack)
{
	t_list	*items;
	int		i;

	items = stack->stack_content;
	i = 1;
	while (items)
	{
		ft_dprintf(g_descriptor,
				"%10d%10s%10d\n", i++, "--->",
				*((int *)(items->content)));
		items = items->next;
	}
}
