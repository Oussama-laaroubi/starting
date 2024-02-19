/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:17:04 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/19 15:27:02 by olaaroub         ###   ########.fr       */
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

void	pa_bonus(t_checker *checker)
{
	if (!checker->head_b)
		return ;
	push_a(&checker->head_a, &checker->head_b);
	checker->stack_b_size--;
	checker->stack_a_size++;
}

void	pb_bonus(t_checker *checker)
{
	if (!checker->head_a)
		return ;
	push_b(&checker->head_a, &checker->head_b);
	checker->stack_b_size++;
	checker->stack_a_size--;
}
