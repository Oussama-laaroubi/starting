# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 18:42:49 by olaaroub          #+#    #+#              #
#    Updated: 2023/12/09 11:35:05 by olaaroub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
RM = rm -rf
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr_base.c ft_placeholder.c ft_putptr_base.c
OBJ = $(SRCS:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ):$(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)


clean:
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY : clean fclean all re