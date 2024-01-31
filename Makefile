# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 10:55:02 by olaaroub          #+#    #+#              #
#    Updated: 2024/01/31 22:28:29 by olaaroub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
# CFLAGS = -fsanitize=address -g3 -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror
src = checks.c fill_stack.c stack_utils.c main.c help.c ./operations/push.c ./operations/rotate.c ./operations/reverse_rotate.c ./operations/swap.c
obj = $(src:.c=.o)
name = push_swap
LIB  = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all : $(name)

$(LIB):
	@make -C libft/

$(PRINTF):
	@make -C ft_printf/

$(name): $(obj) $(PRINTF) $(LIB)
	$(CC) $(CFLAGS) $(obj) $(LIB) $(PRINTF) -o $(name)

clean:
	rm -rf $(obj)
	make clean -C libft
	make clean -C ft_printf

fclean:
	rm -rf $(name) $(obj)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all