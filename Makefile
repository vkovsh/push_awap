NAME				=	push-swap

CC 					=	gcc
CC_FLAGS			=	-Wall -Werror -Wextra

PS_PATH 			=	./push_swap/
PS_SRC_PATH			=	$(PS_PATH)srcs/
INC_PATH			=	$(PS_PATH)includes/ $(LIBFTPRINTF_PATH)includes/ $(LIBFT_PATH)includes/
OBJ_PATH			=	./obj/
LIBFTPRINTF_PATH	=	./libftprintf/
LIBFT_PATH 			=	$(LIBFTPRINTF_PATH)/libft/

OBJ					=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC					=	$(addprefix -I, $(INC_PATH))

OBJ_NAME			=	$(SRC_NAME:.c=.o)

SRC_NAME			=	push_swap.c				\
						initialize.c			\
						push.c					\
						pop.c					\
						push_pop.c				\
						swap.c					\
						is_empty.c 				\
						rotate.c 				\
						rev_rotate.c			\
						do_op.c					\
						is_ascending.c			\
						is_descending.c 		\
						print_stack.c 			\
						swap_i_j.c				\
						get_operation_by_id.c	\
						quicksort.c 			\
						get.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTPRINTF_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFTPRINTF_PATH)libftprintf.a
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(PS_SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@make -C $(LIBFTPRINTF_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."

fclean: clean
	@rm -f $(NAME)
	@echo "Remove [ $(NAME) ]..."

re: fclean all