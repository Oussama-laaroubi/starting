/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:45:47 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/13 20:07:42 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*tmp;
	t_node	*tail;

	tail = find_tail(*head);
	tmp = (*head)->next;
	(*head)->next = NULL;
	tail->next = (*head);
	(*head) = tmp;
}

void	ra(t_node **head_a)
{
	rotate(head_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **head_b)
{
	rotate(head_b);
	write(1, "rb\n", 3);
}

void	rr(t_program *main)
{
	ra(&main->head_a);
	rb(&main->head_b);
}
