# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 10:55:02 by olaaroub          #+#    #+#              #
#    Updated: 2024/01/27 18:36:13 by olaaroub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
src = checks.c initialize.c split.c stack_utils.c main.c
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
	$(CC) $(CFLAGS) $(PRINTF) $(LIB) $(obj) -o $(name)

clean:
	rm -rf $(obj)
	make clean -C libft
	make clean -C ft_printf
fclean:
	rm -rf $(name) $(obj)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all