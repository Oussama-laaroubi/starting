/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:56:56 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/02 21:28:50 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	bool			above_median;
	bool			cheapest;
	int				push_cost;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;
// algoo

void current_index(t_node *head);
void rotate_both(t_node **head_a, t_node **head_b, t_node *lowes_cost);
void r_rotate_both(t_node **head_a, t_node **head_b, t_node *lowest_node);
void start_sorting(t_node **head_a, t_node **head_b);
t_node* lowest_cost(t_node *head);
void configure_nodes_a(t_node *head_a, t_node *head_b);
void configure_nodes_b(t_node *head_a, t_node *head_b);
void adjust_top(t_node **head, t_node *lowest_node, char stack_name);
t_node *min_node(t_node *head);

//algoo
t_node *min_node(t_node *head);
void fill_stack(char **av, t_node **head, char **ptr);
void				init(t_node **tail, t_node **head, int value);
void				append_last(t_node **tail, int value);
void				deallocate_stack(t_node **head);
void				check_numbers(char **av, int ac);
void				check_duplicates(t_node **head);
void				ra(t_node **head);
void				rb(t_node **head);
void				sa(t_node **head);
void				sb(t_node **head);
void				rra(t_node **head);
void				rrb(t_node **head);
void				pb(t_node **head_b, t_node **head);
void				pa(t_node **head_b, t_node **head);
void				rr(t_node **head, t_node **head_b);
void				ss(t_node **head, t_node **head_b);
void				rrr(t_node **head, t_node **head_b);
void				append_beginning(t_node **head, int value);
bool				stack_sorted(t_node *head);
t_node				*find_tail(t_node *head);
void				print_stack(t_node *head);
int					stack_size(t_node *head);
t_node				*max_node(t_node *head);
void				sort_three(t_node **head);
// void	configure_nodes(t_node *head_a, t_node *head_b);

#endif