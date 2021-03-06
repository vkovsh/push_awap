/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:51:11 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 13:51:56 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		push(t_stack *stack, int element)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(&element, sizeof(int));
	ft_lstadd(&(stack->stack_content), new_elem);
	stack->size++;
}
