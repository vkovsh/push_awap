/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_program.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:29:59 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/03 15:30:03 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PROGRAM_H
# define CHECKER_PROGRAM_H
# include "ft_printf.h"

extern struct s_sf	g_flags;

typedef struct	s_sf
{
	t_bool		rewrite;
	t_bool		verbose;
	t_bool		console;
}				t_sf;

#endif
