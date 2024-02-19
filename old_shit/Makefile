# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 10:55:02 by olaaroub          #+#    #+#              #
#    Updated: 2024/02/19 15:26:30 by olaaroub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
#CFLAGS = -fsanitize=address -g3 -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror
SRC = checks.c fill_stack.c print.c ./sorts/sort_three.c stack_utils.c main.c stack_info.c ./operations/push.c ./operations/rotate.c  ./operations/swap.c
SRC += ./sorts/configure_nodes_a.c ./sorts/configure_nodes_b.c ./sorts/move_nodes.c ./sorts/sorting_utils.c ./operations/reverse_rotate.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
LIB  = ../libft/libft.a

all : $(NAME)

$(LIB):
	@make -C ../libft/


$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C ../libft

fclean:
	rm -rf $(NAME) $(OBJ)
	make fclean -C ../libft

re: fclean all
