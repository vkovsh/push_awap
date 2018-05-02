/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:06:20 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/01 12:06:22 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int				main(int ac, char **av)
{
	char		*op_str;
	t_operation	op;

	op_str = NULL;
	if (ac >= 2)
	{
		if (validate_stack_args(ac - 1, &(av[1])))
		{
			initialize(ac - 1, &(av[1]));
			int k = get(g_a, 0);
			ft_printf("%d\n", k);
			while (get_next_line(0, &op_str) == 1 && *op_str)
				if ((op = get_id_by_operation(op_str)) != WRONG_ID)
					do_op(op);
			if (is_ascending(g_a))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}
