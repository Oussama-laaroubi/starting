# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 10:55:02 by olaaroub          #+#    #+#              #
#    Updated: 2024/01/27 11:05:03 by olaaroub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
src = checks.c initialize.c split.c stack_utils.c
obj = $(src:.c=.o)
name = pushswap.a

all : $(name)

$(name): $(obj)
	ar -rc $(name) $(obj)

clean:
	rm -rf $(obj)
fclean:
	rm -rf $(name) $(obj)

re: fclean all