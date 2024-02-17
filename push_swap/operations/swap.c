/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:37:49 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/17 19:29:18 by olaaroub         ###   ########.fr       */
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

void	sa(t_node **head, bool print)
{
	swap(head);
	if(!print)
		ft_printf("sa\n");
}

void	sb(t_node **head_b, bool print)
{
	swap(head_b);
	if(!print)
		ft_printf("sb\n");
}

void	ss(t_node **head, t_node **head_b, bool print)
{
	swap(head);
	swap(head_b);
	if(!print)
		ft_printf("ss\n");
}
