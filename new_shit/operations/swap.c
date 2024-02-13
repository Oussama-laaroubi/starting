/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:37:49 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/13 16:49:24 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_node **head)
{
	t_node	*tmp;

	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	sa(t_node **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_node **head_b)
{
	swap(head_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **head, t_node **head_b)
{
	swap(head);
	swap(head_b);
	write(1, "ss\n", 3);
}
