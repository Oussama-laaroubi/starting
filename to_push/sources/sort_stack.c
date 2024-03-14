/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:20:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/19 15:27:34 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_node **head_a)
{
	if (*head_a == max_node(*head_a))
		ra(head_a, false);
	else if ((*head_a)->next == max_node(*head_a))
		rra(head_a, false);
	if ((*head_a)->next->value < (*head_a)->value)
		sa(head_a, false);
}

void	sort_stack(t_program *main)
{
	if (main->stack_a_size == 2)
		sa(&main->head_a, false);
	else if (main->stack_a_size == 3)
		sort_three(&main->head_a);
	else
		start_sorting(main);
}
