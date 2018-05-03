# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 11:25:01 by vkovsh            #+#    #+#              #
#    Updated: 2018/05/01 11:25:07 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_BIN_NAME			=	push_swap
RAND_BIN_NAME		=	rand
CHECKER_BIN_NAME	=	checker

CC 					=	gcc
CC_FLAGS			=	-g -Wall -Werror -Wextra

PS_PATH 			=	./pushswap/
RAND_PATH			=	./randomizer/
CHECKER_PATH		=	./checker_program/
SHARE_PATH 			=	./share/
INC_PATH			=	$(SHARE_PATH)includes/ $(LIBFTPRINTF_PATH)includes/ $(LIBFT_PATH)includes/
OBJ_PATH 			=	./obj/
PS_OBJ_PATH			=	$(OBJ_PATH)ps_obj/
RAND_OBJ_PATH		=	$(OBJ_PATH)rand_obj/
SHARE_OBJ_PATH		=	$(OBJ_PATH)share_obj/
CHECKER_OBJ_PATH	=	$(OBJ_PATH)checker_obj/
LIBFTPRINTF_PATH	=	./libftprintf/
LIBFT_PATH 			=	$(LIBFTPRINTF_PATH)/libft/

PS_OBJ				=	$(addprefix $(PS_OBJ_PATH),$(PS_OBJ_NAME))

RAND_OBJ 			=	$(addprefix $(RAND_OBJ_PATH),$(RAND_OBJ_NAME))

SHARE_OBJ			=	$(addprefix $(SHARE_OBJ_PATH),$(SHARE_OBJ_NAME))

CHECKER_OBJ 		=	$(addprefix $(CHECKER_OBJ_PATH),$(CHECKER_OBJ_NAME))

INC					=	$(addprefix -I, $(INC_PATH))

PS_OBJ_NAME			=	$(PS_NAME:.c=.o)

RAND_OBJ_NAME		=	$(RAND_NAME:.c=.o)

SHARE_OBJ_NAME		=	$(SHARE_NAME:.c=.o)

CHECKER_OBJ_NAME	=	$(CHECKER_NAME:.c=.o)

CHECKER_NAME		=	checker.c

PS_NAME				=	push_swap.c

RAND_NAME			=	randomizer.c

SHARE_NAME			=	initialize.c			\
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
						get_min_max.c			\
						in_division.c			\
						get_id_by_operation.c	\
						validate_stack_args.c			

all: $(PS_BIN_NAME) $(RAND_BIN_NAME) $(CHECKER_BIN_NAME)

$(CHECKER_BIN_NAME): $(CHECKER_OBJ) $(SHARE_OBJ)
	@make -C $(LIBFTPRINTF_PATH)
	@$(CC) -o $(CHECKER_BIN_NAME) $(SHARE_OBJ) $(CHECKER_OBJ) $(LIBFTPRINTF_PATH)libftprintf.a
	@echo "Compiling" [ $(CHECKER_BIN_NAME) ]

$(PS_BIN_NAME): $(PS_OBJ) $(SHARE_OBJ)
	@make -C $(LIBFTPRINTF_PATH)
	@$(CC) -o $(PS_BIN_NAME) $(SHARE_OBJ) $(PS_OBJ) $(LIBFTPRINTF_PATH)libftprintf.a
	@echo "Compiling" [ $(PS_BIN_NAME) ]

$(RAND_BIN_NAME): $(RAND_OBJ) $(SHARE_OBJ)
	@make -C $(LIBFTPRINTF_PATH)
	@$(CC) -o $(RAND_BIN_NAME) $(SHARE_OBJ) $(RAND_OBJ) $(LIBFTPRINTF_PATH)libftprintf.a
	@echo "Compiling" [ $(RAND_BIN_NAME) ]

$(PS_OBJ_PATH)%.o: $(PS_PATH)%.c
	@mkdir -p $(PS_OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(RAND_OBJ_PATH)%.o: $(RAND_PATH)%.c
	@mkdir -p $(RAND_OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(SHARE_OBJ_PATH)%.o: $(SHARE_PATH)%.c
	@mkdir -p $(SHARE_OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(CHECKER_OBJ_PATH)%.o: $(CHECKER_PATH)%.c
	@mkdir -p $(CHECKER_OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@make -C $(LIBFTPRINTF_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(PS_BIN_NAME) ]..."
	@echo "Cleaning obj [ $(RAND_BIN_NAME) ]..."
	@echo "Cleaning obj [ $(CHECKER_BIN_NAME) ]..."

fclean: clean
	@make -C $(LIBFTPRINTF_PATH) fclean
	@rm -f $(PS_BIN_NAME)
	@rm -f $(RAND_BIN_NAME)
	@rm -f $(CHECKER_BIN_NAME)
	@echo "Remove [ $(PS_BIN_NAME) ]..."
	@echo "Remove [ $(RAND_BIN_NAME) ]..."
	@echo "Remove [ $(CHECKER_BIN_NAME) ]..."

re: fclean all
