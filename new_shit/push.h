/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:20:43 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/09 23:59:19 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "limits.h"
# include "stdbool.h"

# define DEF -77
typedef struct struct_node
{
	int					value;
	int					index;
	struct struct_node	*next;
}						node;

typedef struct s_program
{
	node				*head_a;
	node				*head_b;
	int					stack_b_size;
	int					stack_a_size;
}						t_program;

void					append_last(node **head, int value);
node					*find_tail(node *head);
int						check_args(char **av, int ac);
int						check_duplicates(node **head);
void					ft_error(char *error);
void					deallocate_stack(node **head);
bool					stack_sorted(node *head);
int						stack_size(node *head);
node					*min_node(node *head);
node					*max_node(node *head);
void					ft_indexing(t_program *main);
#endif