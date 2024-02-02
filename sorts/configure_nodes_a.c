/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_nodes_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:57:29 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/02 21:47:40 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	current_index(t_node *head)
{
	int	i;
	int	median;

	if (!head)
		return ;
	i = 0;
	median = stack_size(head) / 2;
	while (head)
	{
		head->index = i;
		if (i <= median)
			head->above_median = true;
		else
			head->above_median = false;
		head = head->next;
		i++;
	}
}

static void	set_target_a(t_node *head_a, t_node *head_b)
{
	t_node	*tmp_b;
	t_node	*target;
	int		best_match_index;

	while (head_a)
	{
		best_match_index = INT_MIN;
		tmp_b = head_b;
		while (tmp_b)
		{
			if ((tmp_b->value < head_a->value)
				&& (tmp_b->value > best_match_index))
			{
				best_match_index = tmp_b->value;
				target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (best_match_index == INT_MIN)
			head_a->target = max_node(head_b);
		else
			head_a->target = target;
		head_a = head_a->next;
	}
}

static void	push_cost(t_node *head_a, t_node *head_b)
{
	int	stack_a_size;
	int	stack_b_size;
	t_node *tmp_a;

	tmp_a = head_a;
	stack_a_size = stack_size(head_a);
	stack_b_size = stack_size(head_b);
	while (tmp_a)
	{
		tmp_a->push_cost = tmp_a->index;
		if (tmp_a->above_median == false)
			tmp_a->push_cost = stack_a_size - (tmp_a->index);
		if (tmp_a->target->above_median == true)
			tmp_a->push_cost += (tmp_a->target->index);
		else
			tmp_a->push_cost += stack_b_size - (tmp_a->target->index);
		tmp_a = tmp_a->next;
	}
}

 static void	calc_lowest_cost(t_node *head)
{
	t_node	*cheapest_node;
	int		lowest_value;

	if (!head)
		return ;
	lowest_value = INT_MAX;
	while (head)
	{
		if (head->push_cost < lowest_value)
		{
			lowest_value = head->push_cost;
			cheapest_node = head;
		}
		head = head->next;
	}
	cheapest_node->cheapest = true;
}

void	configure_nodes_a(t_node *head_a, t_node *head_b)
{
	current_index(head_a);
	current_index(head_b);
	set_target_a(head_a, head_b);
	push_cost(head_a, head_b);
	calc_lowest_cost(head_a);
}
