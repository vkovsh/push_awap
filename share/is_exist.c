/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:19:59 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 13:48:24 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bool		is_exist(t_stack *s, int item)
{
	t_list	*items;
	int		tmp;

	items = s->stack_content;
	while (items)
	{
		tmp = *((int *)(items->content));
		if (tmp == item)
			return (TRUE);
		items = items->next;
	}
	return (FALSE);
}
