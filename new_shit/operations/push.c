/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:51:08 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/13 16:45:03 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_b(t_program *main)
{
	t_node	*tmp;

	tmp = main->head_a->next;
	main->head_a->next = main->head_b;
	main->head_b = main->head_a;
	main->head_a = tmp;
}

static void	push_a(t_program *main)
{
	t_node	*tmp;

	tmp = main->head_b->next;
	main->head_b->next = main->head_a;
	main->head_a = main->head_b;
	main->head_b = tmp;
}

void	pa(t_program *main)
{
	push_a(main);
	main->stack_b_size--;
	main->stack_a_size++;
	write(1, "pa\n", 3);
}

void	pb(t_program *main)
{
	push_b(main);
	main->stack_a_size--;
	main->stack_b_size++;
	write(1, "pb\n", 3);
}
