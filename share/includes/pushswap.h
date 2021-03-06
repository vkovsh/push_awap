/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:42:13 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/01 10:42:19 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "ft_printf.h"
# include <fcntl.h>
# include <time.h>
# include <math.h>

extern struct s_stack	*g_a;
extern struct s_stack	*g_b;
extern int				g_descriptor;

typedef struct	s_stack
{
	size_t		size;
	size_t		head_pointer;
	int			mawaru;
	t_list		*stack_content;
}				t_stack;

typedef enum	e_operation
{
	WRONG_ID = -1,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}				t_operation;

void			initialize(int stack_size, char **args);
t_bool			is_empty(t_stack *stack);
void			push(t_stack *stack, int element);
int				pop(t_stack *stack);
void			push_pop(t_stack *in, t_stack *out);
void			swap(t_stack *stack);
void			rotate(t_stack *stack);
void			rev_rotate(t_stack *stack);
void			do_op(t_operation operation);
t_bool			is_ascending(t_stack *stack);
t_bool			is_descending(t_stack *stack);
void			print_stack(t_stack *stack);
void			swap_i_j(int i, int j);
int				get(t_stack *stack, int i);
const char		*get_operation_by_id(t_operation operation);
t_operation		get_id_by_operation(const char *op_name);
void			quicksort_ascending(t_stack *s, int l, int h,
	void (*f)(int i, int j));
void			quicksort_descending(t_stack *s, int l, int h,
	void (*f)(int i, int j));
int				get_max(t_stack *s);
int				get_min(t_stack *s);
int				in_division(int board, t_stack *s);
t_bool			validate_stack_args(int size, char **args);
t_bool			is_exist(t_stack *s, int item);
int				get_fixed_division(t_stack *s, int number);
void			average_division_a(int aver, int count);
void			average_division_b(int aver, int count);
void			left_joggle(int throw_count);
void			right_joggle(int throw_count);
void			optimisation_condition(void);
void			destruct(t_stack *s);
#endif
