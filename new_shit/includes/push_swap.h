/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:20:43 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/12 19:06:44 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "../../ft_printf/ft_printf.h"
# include "../../libft/libft.h"
# include "limits.h"
# include "stdbool.h"

# define DEF -77

typedef struct struct_node
{
	int					value;
	int					index;
	int					position;
	int					target_position;
	int					cost;
	int					target_cost;
	struct struct_node	*next;
}						node;

typedef struct s_program
{
	node				*head_a;
	node				*head_b;
	size_t				stack_b_size;
	size_t				stack_a_size;
}						t_program;

struct					s_lowest_cost
{
	t_program			*main;
	int					cost_at_b;
	int					cost_at_a;
};

node					*max_node(node *head);
node					*find_tail(node *head);
node					*min_node(node *head);
int						check_args(char **av, int ac);
int						check_duplicates(node **head);
size_t					stack_size(node *head);
bool					stack_sorted(node *head);
void					append_last(node **head, int value);
void					ft_error(char *error);
void					deallocate_stack(node **head);

void					sa(node **head);
void					ra(node **head_a);
void					pa(t_program *main);
void					pb(t_program *main);
void					rra(node **head_a);
void					rrb(node **head_b);
void					rb(node **head_b);
void					rr(t_program *main);
void					rrr(t_program *main);

void					ft_indexing(t_program *main);
void					sort_stack(t_program *main);
void					sort_three(node **head_a);

void					start_sorting(t_program *main);
void					set_positions(node *head);
int						get_target_position(t_program *main, int index,
							int closest, int target_position);
void					set_cost(t_program *main);
void					single_rotate_a(t_program *main, int *cost_at_a);
void					single_rotate_b(t_program *main, int *cost_at_b);
void					execute_move(struct s_lowest_cost best_move);
void					get_min_node_position(node *head_a,
							int *min_node_position);

#endif