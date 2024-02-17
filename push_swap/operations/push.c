/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:51:08 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/17 20:52:56 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_b(t_node** head_a, t_node** head_b)
{
	t_node	*tmp;

	tmp = (*head_a)->next;
	(*head_a)->next = *head_b;
	*head_b = *head_a;
	*head_a = tmp;
}

static void	push_a(t_node** head_a, t_node** head_b)
{
	t_node	*tmp;

	tmp = (*head_b)->next;
	(*head_b)->next = *head_a;
	*head_a = *head_b;
	*head_b = tmp;
}

void	pb(t_program *main, bool print)
{
	push_b(&main->head_a, &main->head_b);
	main->stack_a_size--;
	main->stack_b_size++;
	if(!print)
		ft_printf("pb\n");
}

void	pa(t_program *main, bool print)
{
	push_a(&main->head_a, &main->head_b);
	main->stack_b_size--;
	main->stack_a_size++;
	if(!print)
		ft_printf("pa\n");
}

void	pa_bonus(t_checker *checker)
{
	push_a(&checker->head_a, &checker->head_b);
	checker->stack_b_size--;
	checker->stack_a_size++;
}

void	pb_bonus(t_checker *checker)
{
	push_b(&checker->head_a, &checker->head_b);
	checker->stack_b_size++;
	checker->stack_a_size--;
}
