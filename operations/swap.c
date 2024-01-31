/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:37:49 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/31 15:41:59 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_node **head)
{
	t_node	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->previous = (*head)->previous;
	(*head)->previous = tmp;
	if (tmp->next != NULL)
	{
		tmp->next->previous = *head;
	}
	tmp->next = *head;
	*head = tmp;
}

void	sa(t_node **head)
{
	swap(head);
	ft_printf("sa\n");
}

void	sb(t_node **head_b)
{
	swap(head_b);
	ft_printf("sb\n");
}

void	ss(t_node **head, t_node **head_b)
{
	swap(head);
	swap(head_b);
	ft_printf("ss\n");
}
