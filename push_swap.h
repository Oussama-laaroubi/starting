/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:56:56 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/01 15:33:55 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

void				fill_stack(char **av, t_node **head, char **ptr);
void				init(t_node **tail, t_node **head, int value);
void				append_last(t_node **tail, int value);
void				deallocate_stack(t_node **head);
void				check_numbers(char **av, int ac);
void				check_duplicates(t_node **head);
long				ft_atol(char *str);
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
int	stack_size(t_node* head);
t_node* max_node(t_node* head);
void    sort_three(t_node** head);


#endif