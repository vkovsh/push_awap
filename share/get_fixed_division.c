/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fixed_division.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:32:43 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 15:32:45 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		get_fixed_division(t_stack *s, int number)
{
	int	max;

	max = get_max(s);
	while (in_division(max, s) < number)
		max--;
	while (!is_exist(s, max))
		max--;
	return (max);
}
