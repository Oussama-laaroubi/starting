/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps_for_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:30:25 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/12 18:12:34 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	set_positions(node *head)
{
	node	*curr;
	int		position;

	position = 0;
	curr = head;
	while (curr)
	{
		curr->position = position++;
		curr = curr->next;
	}
}

int	get_target_position(t_program *main, int index, int closest,
		int target_position)
{
	node	*current;

	current = main->head_a;
	while (current)
	{
		if (current->index > index && current->index < closest)
		{
			closest = current->index;
			target_position = current->position;
		}
		current = current->next;
	}
	if (closest != INT_MAX)
		return (target_position);
	current = main->head_a;
	while (current)
	{
		if (current->index < closest)
		{
			closest = current->index;
			target_position = current->position;
		}
		current = current->next;
	}
	return (target_position);
}

void	set_cost(t_program *main)
{
	node	*current_a;
	node	*current_b;

	current_a = main->head_a;
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

void	single_rotate_a(t_program *main, int *cost_at_a)
{
	while (*cost_at_a)
	{
		if (*cost_at_a < 0)
		{
			rra(&main->head_a);
			*(cost_at_a) += 1;
		}
		else if (*cost_at_a > 0)
		{
			ra(&main->head_a);
			*(cost_at_a) -= 1;
		}
	}
}

void	single_rotate_b(t_program *main, int *cost_at_b)
{
	while (*cost_at_b)
	{
		if (*cost_at_b < 0)
		{
			rra(&main->head_b);
			*(cost_at_b) += 1;
		}
		else if (*cost_at_b > 0)
		{
			ra(&main->head_b);
			*(cost_at_b) -= 1;
		}
	}
}

void	execute_move(struct s_lowest_cost best_move)
{
	if (best_move.cost_at_a < 0 && best_move.cost_at_b < 0)
	{
		while (best_move.cost_at_a < 0 && best_move.cost_at_b < 0)
		{
			rrr(best_move.main);
			best_move.cost_at_a++;
			best_move.cost_at_b++;
		}
	}
	else if (best_move.cost_at_a > 0 && best_move.cost_at_b > 0)
	{
		while (best_move.cost_at_a > 0 && best_move.cost_at_b > 0)
		{
			rr(best_move.main);
			best_move.cost_at_a--;
			best_move.cost_at_b--;
		}
	}
	single_rotate_a(best_move.main, &best_move.cost_at_a);
	single_rotate_b(best_move.main, &best_move.cost_at_b);
	pa(best_move.main);
}

void	get_min_node_position(node *head_a, int *min_node_position)
{
	node	*current;
	int		least_rank;

	least_rank = INT_MAX;
	current = head_a;
	while (current)
	{
		if (current->index < least_rank)
		{
			*min_node_position = current->position;
			least_rank = current->index;
		}
		current = current->next;
	}
}
