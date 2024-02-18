/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:45:47 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/18 10:18:53 by olaaroub         ###   ########.fr       */
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

void	ra(t_node **head_a, bool print)
{
	rotate(head_a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_node **head_b, bool print)
{
	rotate(head_b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_program *main, bool print)
{
	rotate(&main->head_a);
	rotate(&main->head_b);
	if (!print)
		ft_printf("rr\n");
}

void	rr_bonus(t_checker *checker)
{
	rotate(&checker->head_a);
	rotate(&checker->head_b);
}
