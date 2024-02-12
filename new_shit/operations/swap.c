/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:37:49 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/12 19:09:45 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(node **head)
{
	node	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	sa(node **head)
{
	swap(head);
	ft_printf("sa\n");
}

void	sb(node **head_b)
{
	swap(head_b);
	ft_printf("sb\n");
}

void	ss(node **head, node **head_b)
{
	swap(head);
	swap(head_b);
	ft_printf("ss\n");
}
