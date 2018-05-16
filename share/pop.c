/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:49:10 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 13:49:13 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			pop(t_stack *stack)
{
	t_list	*tmp;
	int		pop_element;

	tmp = stack->stack_content;
	pop_element = *((int *)(tmp->content));
	stack->stack_content = tmp->next;
	free(tmp->content);
	free(tmp);
	stack->size--;
	return (pop_element);
}
