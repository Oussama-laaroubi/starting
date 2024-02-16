/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:20:06 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/15 19:03:33 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*lowest_node(t_node *head)
{
	t_node	*min;
	int		lowest_val;

	min = NULL;
	lowest_val = INT_MAX;
	while (head)
	{
		if (head->value <= lowest_val && head->index == DEF)
		{
			min = head;
			lowest_val = head->value;
		}
		head = head->next;
	}
	return (min);
}

void	set_positions(t_node *head)
{
	t_node	*curr;
	int		position;

	position = 0;
	curr = head;
	while (curr)
	{
		curr->position = position++;
		curr = curr->next;
	}
}

void	set_cost(t_program *main)
{
	t_node	*current_b;

	current_b = main->head_b;
	while (current_b)
	{
		current_b->cost = current_b->position;
		if ((size_t)current_b->position > main->stack_b_size / 2)
			current_b->cost = (main->stack_b_size - current_b->position) * -1;
		current_b->target_cost = current_b->target_position;
		if ((size_t)current_b->target_position > main->stack_a_size / 2)
			current_b->target_cost = (main->stack_a_size
					- current_b->target_position) * -1;
		current_b = current_b->next;
	}
}

void	ft_indexing(t_program *main)
{
	t_node	*min_node;
	t_node	*tmp;
	int		index;

	tmp = main->head_a;
	index = 0;
	while (tmp)
	{
		min_node = lowest_node(main->head_a);
		min_node->index = index++;
		tmp = tmp->next;
	}
}
