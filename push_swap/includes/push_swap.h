#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "ft_printf.h"
# include "stack.h"

extern struct s_stack   *g_a;
extern struct s_stack   *g_b;

typedef enum	e_operation
{
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
int             arithmetic_mean(t_stack *stack);
t_bool          is_ascending(t_stack *stack);
t_bool          is_descending(t_stack *stack);
int             min_position(t_stack *stack, int *min);
int             max_position(t_stack *stack, int *max);
void            print_stack(t_stack *stack);
void            swap_i_j(int i, int j);
int             get(int i);
const char      *get_operation_by_id(t_operation operation);
void            quicksort(int l, int h);
#endif