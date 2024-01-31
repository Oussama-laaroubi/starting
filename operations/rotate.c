/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:42:24 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/31 16:08:03 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_node **head, t_node **tail)
{
	t_node	*top;

	if (*head == NULL)
		return ;
	top = (*head)->next;
	(*tail)->next = *head;
	(*head)->next = NULL;
	top->previous = NULL;
	(*head)->previous = *tail;
	(*tail) = (*head);
	(*head) = top;
}

void	ra(t_node **head)
{
	t_node	*tail;

	tail = find_tail(*head);
	rotate(head, &tail);
	ft_printf("ra\n");
}

void	rb(t_node **head_b)
{
	t_node	*tail_b;

	tail_b = find_tail(*head_b);
	rotate(head_b, &tail_b);
	ft_printf("rb\n");
}

void	rr(t_node **head, t_node **head_b)
{
	t_node	*tail;
	t_node	*tail_b;

	tail = find_tail(*head);
	tail_b = find_tail(*head_b);
	rotate(head, &tail);
	rotate(head_b, &tail_b);
	ft_printf("rr");
}
