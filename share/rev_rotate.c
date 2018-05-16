/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:37:56 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 14:38:10 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rev_rotate(t_stack *stack)
{
	ft_lstrev(&(stack->stack_content));
	rotate(stack);
	ft_lstrev(&(stack->stack_content));
}
