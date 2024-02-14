CC = cc
# CFLAGS = -fsanitize=address -g3 -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror
SRC = ./srcs/actions_1.c ./srcs/actions_2.c ./srcs/actions_3.c ./srcs/handling.c ./srcs/helps.c
SRC += ./srcs/main.c ./srcs/program.c ./srcs/push_swap_exec.c ./srcs/sort_stack.c ./srcs/stack_help_1.c
SRC += ./srcs/stack_help_2.c ./srcs/stack_position.c ./srcs/tiny_sort.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
LIB  = ./libft/libft.a

all : $(NAME)

$(LIB):
	make -C ./libft/


$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C ./libft

fclean:
	rm -rf $(NAME) $(OBJ)
	make fclean -C ./libft

re: fclean all
