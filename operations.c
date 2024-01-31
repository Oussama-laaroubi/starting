/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:36:14 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/31 16:19:22 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"






}

void	pa(t_node **head_b, t_node **head)
{
	t_node	*tmp;

	if (*head_b == NULL)
		return ;
	if ((*head_b)->next == NULL)
		tmp = *head_b;
	tmp = (*head_b)->next;
	// printf("im here");
	append_beginning(head, (*head_b)->value);
	// tmp->previous = NULL;
	(*head_b) = tmp;
	ft_printf("pa\n");
}
void	ss(t_node **head, t_node **head_b)
{
	sa(head);
	sb(head_b);
	ft_printf("ss\n");
}
void	rr(t_node **head, t_node **head_b)
{
	t_node *tail = find_tail(*head);
	t_node *tail_b = find_tail(*head_b);
	ra(head, &tail);
	rb(head_b, &tail_b);
	ft_printf("rr\n");
}

void	rrr(t_node **head, t_node **head_b)
{
	t_node	*tail;
	t_node	*tail_b;

	if (*head == NULL)
		return ;
	tail = find_tail(*head);
	tail_b = find_tail(*head_b);
	rra(head, &tail);
	rrb(head_b, &tail_b);
	ft_printf("rrr\n");
}