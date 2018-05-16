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
#include "checker_program.h"

struct s_sf g_flags;

static inline void	create_log(void)
{
	time_t			t;
	struct tm		tm;

	open("log", O_CREAT | O_EXCL);
	system("chmod 666 log");
	if (g_flags.console == TRUE)
		g_descriptor = 1;
	else if (g_flags.rewrite == FALSE)
		g_descriptor = open("log", O_WRONLY | O_APPEND);
	else if (g_flags.rewrite == TRUE)
		g_descriptor = open("log", O_WRONLY | O_TRUNC);
	t = time(NULL);
	tm = *localtime(&t);
	ft_dprintf(g_descriptor,
		"now: %d-%d-%d %d:%d:%d\n",
		tm.tm_year + 1900,
		tm.tm_mon + 1,
		tm.tm_mday,
		tm.tm_hour,
		tm.tm_min,
		tm.tm_sec);
	ft_dprintf(g_descriptor, "%s\n", "STACK");
}

static inline void	parsing_flags(int *split, int ac, char **av)
{
	ft_bzero(&g_flags, sizeof(t_sf));
	*split = 1;
	while (av[(*split)][0] == '-' && *split < ac)
	{
		if (!ft_strcmp(av[(*split)], "-r") ||
			!ft_strcmp(av[(*split)], "-rewrite"))
			g_flags.rewrite = TRUE;
		else if (!ft_strcmp(av[(*split)], "-v") ||
			!ft_strcmp(av[(*split)], "-verbose"))
			g_flags.verbose = TRUE;
		else if (!ft_strcmp(av[(*split)], "-c") ||
			!ft_strcmp(av[(*split)], "-console"))
			g_flags.console = TRUE;
		else
			break ;
		(*split)++;
	}
}

static inline void	operation_listing(void)
{
	char			*op_str;
	t_operation		op;

	if (g_flags.verbose)
	{
		ft_dprintf(g_descriptor, "VERBOSE MODE\n");
		while (get_next_line(0, &op_str) == 1 && *op_str)
			if ((op = get_id_by_operation(op_str)) != WRONG_ID)
			{
				ft_dprintf(g_descriptor, "Operation: ");
				do_op(op);
				ft_dprintf(g_descriptor, "Stack a\n");
				print_stack(g_a);
				ft_dprintf(g_descriptor, "Stack b\n");
				print_stack(g_b);
				ft_strdel(&op_str);
			}
	}
	else
		while (get_next_line(0, &op_str) == 1 && *op_str)
		{
			if ((op = get_id_by_operation(op_str)) != WRONG_ID)
				do_op(op);
			ft_strdel(&op_str);
		}
}

static inline void	check(void)
{
	create_log();
	print_stack(g_a);
	ft_dprintf(g_descriptor, "%s\n", "OPERATION LIST");
	operation_listing();
	ft_dprintf(g_descriptor, "%s\n", "RESULTING STACK");
	print_stack(g_a);
	if (is_ascending(g_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	write(g_descriptor, "\n", 1);
	close(g_descriptor);
}

int					main(int ac, char **av)
{
	int				split;

	if (ac >= 2)
	{
		parsing_flags(&split, ac, av);
		if (validate_stack_args(ac - split, &(av[split])))
		{
			initialize(ac - split, &(av[split]));
			check();
			destruct(g_a);
			destruct(g_b);
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}
