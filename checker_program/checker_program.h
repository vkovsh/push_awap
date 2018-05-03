#ifndef CHECKERPROGRAM_H
# define CHECKERPROGRAM_H
# include "ft_printf.h"

extern struct s_sf	g_flags;

typedef struct	s_sf
{
	t_bool		rewrite;
	t_bool		verbose;
	t_bool		console;
}				t_sf;

#endif