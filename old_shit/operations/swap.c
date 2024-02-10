/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:37:49 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/10 02:26:13 by olaaroub         ###   ########.fr       */
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
	tmp->next = *head;
	*head = tmp;
}

void	sa(t_node **head)
{
	if(!*head || !head)
		return;
	swap(head);
	ft_printf("sa\n");
}

void	sb(t_node **head_b)
{
	if(!*head_b || !head_b)
		return;
	swap(head_b);
	ft_printf("sb\n");
}

void	ss(t_node **head, t_node **head_b)
{
	if(!*head || !(*head_b) || !head || !head_b)
		return;
	swap(head);
	swap(head_b);
	ft_printf("ss\n");
}
