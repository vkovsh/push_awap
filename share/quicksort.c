/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:53:37 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/16 14:37:28 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	partition_ascending(t_stack *s, int l, int h,
		void (*f)(int i, int j))
{
	int		pivot;
	int		i;
	int		j;

	pivot = get(s, l);
	i = l - 1;
	j = h + 1;
	while (1)
	{
		while (get(s, ++i) < pivot)
			continue ;
		while (get(s, --j) > pivot)
			continue ;
		if (i >= j)
			return (j);
		f(i, j);
	}
	return (0);
}

void		quicksort_ascending(t_stack *s, int l, int h,
		void (*f)(int i, int j))
{
	int		pivot;

	if (l != h)
	{
		pivot = partition_ascending(s, l, h, f);
		quicksort_ascending(s, l, pivot, f);
		quicksort_ascending(s, pivot + 1, h, f);
	}
}
