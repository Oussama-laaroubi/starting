/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:20:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/11 16:33:00 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_three(node **head_a)
{
	if (*head_a == max_node(*head_a))
		ra(head_a);
	else if ((*head_a)->next == max_node(*head_a))
		rra(head_a);
	if ((*head_a)->next->value < (*head_a)->value)
		sa(head_a);
}

void	sort_stack(t_program *main)
{
	if (main->stack_a_size == 2)
		sa(&main->head_a);
	else if (main->stack_a_size == 3)
		sort_three(&main->head_a);
	else
		start_sorting(main);
}
