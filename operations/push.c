/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:59:48 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/07 14:22:57 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_b(t_node **head_b, t_node **head_a)
{
	t_node	*tmp;

	if (*head_a == NULL)
		return ;
	tmp = (*head_a)->next;
	append_beginning(head_b, (*head_a)->value);
	free(*head_a);
	*head_a = NULL;
	(*head_a) = tmp;
}

static void	push_a(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	if (*head_b == NULL)
		return ;
	// if ((*head_b)->next == NULL)
	// 	tmp = *head_b;
	tmp = (*head_b)->next;
	append_beginning(head_a, (*head_b)->value);
	// free(*head_b);
	(*head_b) = tmp;
}

void	pa(t_node **head_a, t_node **head_b)
{
	push_a(head_a, head_b);
	ft_printf("pa\n");
}

void	pb(t_node **head_b, t_node **head_a)
{
	push_b(head_b, head_a);
	ft_printf("pb\n");
}
