/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:44:29 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 13:45:33 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct s_stack	*g_a;
struct s_stack	*g_b;

void		initialize(int stack_size, char **args)
{
	g_a = (t_stack *)malloc(sizeof(t_stack));
	g_b = (t_stack *)malloc(sizeof(t_stack));
	ft_bzero(g_a, sizeof(t_stack));
	ft_bzero(g_b, sizeof(t_stack));
	while (stack_size--)
		push(g_a, ft_atoi(args[stack_size]));
}

void		destruct(t_stack *s)
{
	t_list	*tmp;

	while (s->stack_content)
	{
		tmp = s->stack_content->next;
		free(s->stack_content->content);
		free(s->stack_content);
		s->stack_content = tmp;
	}
	free(s);
}
