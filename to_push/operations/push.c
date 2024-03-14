/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:51:08 by olaaroub          #+#    #+#             */
/*   Updated: 2024/03/01 12:27:19 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_b(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	tmp = (*head_a)->next;
	(*head_a)->next = *head_b;
	*head_b = *head_a;
	*head_a = tmp;
}

static void	push_a(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	tmp = (*head_b)->next;
	(*head_b)->next = *head_a;
	*head_a = *head_b;
	*head_b = tmp;
}

void	pb(t_program *main)
{
	if (!main->head_a)
		return ;
	push_b(&main->head_a, &main->head_b);
	main->stack_a_size--;
	main->stack_b_size++;
	ft_printf("pb\n");
}

void	pa(t_program *main)
{
	if (!main->head_b)
		return ;
	push_a(&main->head_a, &main->head_b);
	main->stack_b_size--;
	main->stack_a_size++;
	ft_printf("pa\n");
}
