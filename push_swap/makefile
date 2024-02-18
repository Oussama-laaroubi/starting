# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 23:13:39 by olaaroub          #+#    #+#              #
#    Updated: 2024/02/18 12:02:45 by olaaroub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

# CFLAGS = -fsanitize=address -g3 -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror

SRC = ./sources/main.c ./sources/stack_utils.c ./sources/all_checks.c ./sources/indexing.c ./sources/sort_stack.c
SRC += ./sources/helps_for_sort.c ./sources/start_sorting.c ./sources/stack_specs.c
SRC += ./operations/reverse_rotate.c ./operations/push.c ./operations/swap.c ./operations/rotate.c

B_SRCS = ./bonus/read_instructions.c ./bonus/stack_utils_bonus.c ./sources/all_checks.c ./sources/stack_specs.c
B_SRCS += ./operations/reverse_rotate.c ./operations/push.c ./operations/swap.c ./operations/rotate.c ./operations/push_bonus.c

OBJ = $(SRC:.c=.o)

B_OBJ= $(B_SRCS:.c=.o)

NAME = push_swap
B_NAME = checker_bonus

LIB  = ../libft/libft.a

mandatory : $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(LIB):
	make -C ../libft/

bonus :	$(B_NAME)

$(B_NAME) : $(B_OBJ) $(LIB)
	 $(CC) $(CFLAGS) $(B_OBJ) $(LIB) -o $(B_NAME)

clean:
	rm -rf $(OBJ) $(B_OBJ)
	make clean -C ../libft

fclean:
	rm -rf $(NAME) $(OBJ) $(B_OBJ) $(B_NAME)
	make fclean -C ../libft

re: fclean mandatory


