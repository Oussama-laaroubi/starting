# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 23:13:39 by olaaroub          #+#    #+#              #
#    Updated: 2024/02/10 00:01:46 by olaaroub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -fsanitize=address -g3 -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror
SRC = newmain.c stack_utils.c all_checks.c indexing.c stack_specs.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
LIB  = ../libft/libft.a
PRINTF = ../ft_printf/libftprintf.a

all : $(NAME)

$(LIB):
	@make -C ../libft/

$(PRINTF):
	@make -C ../ft_printf/

$(NAME): $(OBJ) $(PRINTF) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(PRINTF) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C ../libft
	make clean -C ../ft_printf

fclean:
	rm -rf $(NAME) $(OBJ)
	make fclean -C ../libft
	make fclean -C ../ft_printf

re: fclean all
