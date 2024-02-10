/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:49:47 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/10 02:25:22 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_node **head, t_node **tail)
{
	t_node	*bottom;

	if (*head == NULL)
		return ;
	bottom = (*tail)->previous;
	bottom->next = NULL;
	(*tail)->previous = NULL;
	(*head)->previous = (*tail);
	if ((*head) != NULL)
		(*tail)->next = (*head);
	(*head) = (*tail);
	(*tail) = bottom;
}

void	rra(t_node **head)
{
	t_node	*tail;

	if(!*head || !head)
		return;
	tail = find_tail(*head);
	reverse_rotate(head, &tail);
	ft_printf("rra\n");
}

void	rrb(t_node **head_b)
{
	t_node	*tail_b;
	if(!*head_b || !head_b)
		return;
	tail_b = find_tail(*head_b);
	reverse_rotate(head_b, &tail_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **head, t_node **head_b)
{
	t_node	*tail;
	t_node	*tail_b;
	if(!*head || !*head_b || !head || !head_b)
		return;
	tail = find_tail(*head);
	tail_b = find_tail(*head_b);
	reverse_rotate(head, &tail);
	reverse_rotate(head_b, &tail_b);
	ft_printf("rrr\n");
}
