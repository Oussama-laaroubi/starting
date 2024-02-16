/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:20:43 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/15 19:10:59 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
}						t_node;

typedef	struct s_checker
{
	t_node				*head_a;
	t_node				*head_b;
	size_t				stack_b_size;
	size_t				stack_a_size;
}						t_checker;

typedef struct s_program
{
	t_node				*head_a;
	t_node				*head_b;
	size_t				stack_b_size;
	size_t				stack_a_size;
}						t_program;

struct					s_lowest_cost
{
	t_program			*main;
	int					cost_at_b;
	int					cost_at_a;
};

t_node					*max_node(t_node *head);
t_node					*find_tail(t_node *head);
t_node					*min_node(t_node *head);
int						check_args(char **av, int ac);
int						check_duplicates(t_node **head);
size_t					stack_size(t_node *head);
bool					stack_sorted(t_node *head);
void					append_last(t_node **head, int value);
void					ft_error(char *error);
void					free_when_error(char **ptr);
void					deallocate_stack(t_node **head);

void					sa(t_node **head);
void					ra(t_node **head_a);
void					pa(t_program *main);
void					pb(t_program *main);
void					rra(t_node **head_a);
void					rrb(t_node **head_b);
void					rb(t_node **head_b);
void					rr(t_program *main);
void					rrr(t_program *main);

void					ft_indexing(t_program *main);
void					sort_stack(t_program *main);
void					sort_three(t_node **head_a);

void					start_sorting(t_program *main);
void					set_positions(t_node *head);
int						get_target_position(t_program *main, int index,
							int closest, int target_position);
void					set_cost(t_program *main);
void					single_rotate_a(t_program *main, int *cost_at_a);
void					single_rotate_b(t_program *main, int *cost_at_b);
void					execute_move(struct s_lowest_cost best_move);
void					get_min_node_position(t_node *head_a,
							int *min_node_position);

#endif