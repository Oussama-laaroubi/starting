/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_nodes_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:58:37 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/04 17:21:16 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target(t_node *head_a, t_node *head_b)
{
	t_node	*curr_a;
	t_node	*target;
	long	best_match_index;

	while (head_b)
	{
		best_match_index = LONG_MAX;
		curr_a = head_a;
		while (curr_a)
		{
			if (curr_a->value > head_b->value
				&& curr_a->value < best_match_index)
			{
				best_match_index = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match_index == LONG_MAX)
			head_b->target = min_node(head_a);
		else
			head_b->target = target;
		head_b = head_b->next;
	}
}

void	configure_nodes_b(t_node *head_a, t_node *head_b)
{
	current_index(head_a);
	current_index(head_b);
	set_target(head_a, head_b);
}
