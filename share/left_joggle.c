/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_joggle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:27:01 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 15:27:05 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	left_joggle(int throw_count)
{
	int	half_max;

	if (!throw_count)
		return ;
	if (throw_count > (int)(g_a->size))
		throw_count = (int)(g_a->size);
	if (throw_count <= 3)
		quicksort_ascending(g_a, 0, g_a->size - 1, &swap_i_j);
	else
	{
		half_max = throw_count / 2;
		average_division_a(get_fixed_division(g_a, g_a->size - half_max),
			half_max);
		left_joggle(half_max);
		right_joggle(half_max);
	}
}
