/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:41:57 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/12 20:29:59 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*tmp;
	t_node	*tail;

	if (!(*head))
		return ;
	tmp = *head;
	tail = find_tail(*head);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	tail->next = (*head);
	*head = tail;
}

void	rra(t_node **head_a)
{
	if (!*head_a)
		return ;
	reverse_rotate(head_a);
	ft_printf("rra\n");
}

void	rrb(t_node **head_b)
{
	if (!*head_b)
		return ;
	reverse_rotate(head_b);
	ft_printf("rrb\n");
}

void	rrr(t_program *main)
{
	if (!main->head_a || !main->head_b)
		return ;
	reverse_rotate(&main->head_a);
	reverse_rotate(&main->head_b);
	ft_printf("rrr\n");
}
