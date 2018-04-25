#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "ft_printf.h"
# include "stack.h"

extern struct s_stack   *g_a;
extern struct s_stack   *g_b;

void    initialize(int stack_size, char **args);
t_bool  is_empty(t_stack *stack);
void    push(t_stack *stack, int element);
int     pop(t_stack *stack);
void    push_pop(t_stack *in, t_stack *out);
void    swap(t_stack *stack);
void    rotate(t_stack *stack);
void    rev_rotate(t_stack *stack);
#endif