/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:59:48 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/01 14:17:35 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_b(t_node **head_b, t_node **head)
{
	t_node	*tmp;

	if (*head == NULL)
		return ;
	tmp = (*head)->next;
	append_beginning(head_b, (*head)->value);
	free(*head);
	*head = NULL;
	(*head) = tmp;
}

static void	push_a(t_node **head_b, t_node **head)
{
	t_node	*tmp;

	if (*head_b == NULL)
		return ;
	if ((*head_b)->next == NULL)
		tmp = *head_b;
	tmp = (*head_b)->next;
	append_beginning(head, (*head_b)->value);
	free(*head_b);
	(*head_b) = tmp;
	ft_printf("pa\n");
}

void	pa(t_node **head, t_node **head_b)
{
	push_a(head, head_b);
	ft_printf("pa\n");
}

void	pb(t_node **head, t_node **head_b)
{
	push_b(head_b, head);
	ft_printf("pb\n");
}
