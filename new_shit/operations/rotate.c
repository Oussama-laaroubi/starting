/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:45:47 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/12 20:30:08 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*tmp;
	t_node	*tail;

	if (!*head)
		return ;
	tail = find_tail(*head);
	tmp = (*head)->next;
	(*head)->next = NULL;
	tail->next = (*head);
	(*head) = tmp;
}

void	ra(t_node **head_a)
{
	if (!*head_a)
		return ;
	rotate(head_a);
	ft_printf("ra\n");
}

void	rb(t_node **head_b)
{
	if (!*head_b)
		return ;
	rotate(head_b);
	ft_printf("rb\n");
}

void	rr(t_program *main)
{
	if (!main->head_b || !main->head_a)
		return ;
	rotate(&main->head_a);
	rotate(&main->head_b);
	ft_printf("rr\n");
}
