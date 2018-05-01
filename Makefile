NAME				=	push-swap
NAME2				=	rand

CC 					=	gcc
CC_FLAGS			=	-Wall -Werror -Wextra

PS_PATH 			=	./push_swap/
RAND_PATH			=	./randomizer/
PS_SRC_PATH			=	$(PS_PATH)srcs/
INC_PATH			=	$(PS_PATH)includes/ $(LIBFTPRINTF_PATH)includes/ $(LIBFT_PATH)includes/
OBJ_PATH			=	./obj/
OBJ2_PATH			=	./obj2/
LIBFTPRINTF_PATH	=	./libftprintf/
LIBFT_PATH 			=	$(LIBFTPRINTF_PATH)/libft/

OBJ					=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

OBJ2 				=	$(addprefix $(OBJ2_PATH),$(OBJ2_NAME))

INC					=	$(addprefix -I, $(INC_PATH))

OBJ_NAME			=	$(SRC_NAME:.c=.o)

OBJ2_NAME			=	$(RAND_NAME:.c=.o)

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
						get.c					\
						swap_i_j_in_b.c			\
						get_min_max.c			\
						in_division.c				

RAND_NAME			=	randomizer.c

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C $(LIBFTPRINTF_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFTPRINTF_PATH)libftprintf.a
	@echo "Compiling" [ $(NAME) ]

$(NAME2): $(OBJ2)
	@make -C $(LIBFTPRINTF_PATH)
	@$(CC) -o $(NAME2) $(OBJ2) $(LIBFTPRINTF_PATH)libftprintf.a
	@echo "Compiling" [ $(NAME2) ]

$(OBJ_PATH)%.o: $(PS_SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ2_PATH)%.o: $(RAND_PATH)%.c
	@mkdir -p $(OBJ2_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@make -C $(LIBFTPRINTF_PATH) clean
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ2_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."
	@echo "Cleaning obj [ $(NAME2) ]..."

fclean: clean
	@rm -f $(NAME2)
	@rm -f $(NAME)
	@echo "Remove [ $(NAME) ]..."
	@echo "Remove [ $(NAME2) ]..."

re: fclean all