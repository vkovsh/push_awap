#ifndef STACK_H
# define STACK_H
# include "ft_printf.h"

typedef struct  s_stack
{
    size_t      size;
    size_t      head_pointer;
    t_list      *stack_content;
}               t_stack;
#endif