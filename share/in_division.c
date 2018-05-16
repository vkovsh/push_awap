/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_division.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:41:39 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 13:41:43 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			in_division(int board, t_stack *s)
{
	int		in;
	t_list	*items;

	in = 0;
	items = s->stack_content;
	while (items)
	{
		if (*((int *)(items->content)) >= board)
			in++;
		items = items->next;
	}
	return (in);
}
