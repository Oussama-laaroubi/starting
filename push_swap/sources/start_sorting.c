/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:23:40 by olaaroub          #+#    #+#             */
/*   Updated: 2024/03/01 10:42:58 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_b_until_three(t_program *main, size_t size)
{
	size_t	pushed_to_b;

	pushed_to_b = 0;
	while (size > 6 && pushed_to_b < size / 2)
	{
		if ((size_t)main->head_a->index <= size / 2)
		{
			pb(main, false);
			pushed_to_b++;
		}
		else
			ra(&main->head_a, false);
	}
	while (size - pushed_to_b > 3)
	{
		pb(main, false);
		pushed_to_b++;
	}
}

static void	set_targets(t_program *main)
{
	t_node	*current;
	int		target_position;

	current = main->head_b;
	set_positions(main->head_a);
	set_positions(main->head_b);
	target_position = 0;
	while (current)
	{
		target_position = get_target_position(main, current->index, INT_MAX,
				target_position);
		current->target_position = target_position;
		current = current->next;
	}
}

static void	find_best_move(t_program *main)
{
	struct s_lowest_cost	best_move;
	t_node					*current;
	int						lowest_cost;

	lowest_cost = INT_MAX;
	current = main->head_b;
	while (current)
	{
		if (ft_abs(current->cost)
			+ ft_abs(current->target_cost) < ft_abs(lowest_cost))
		{
			lowest_cost = ft_abs(current->cost) + ft_abs(current->target_cost);
			best_move.cost_at_a = current->target_cost;
			best_move.cost_at_b = current->cost;
		}
		current = current->next;
	}
	best_move.main = main;
	execute_move(best_move);
}

static void	rotate_until_min_is_top(t_program *main, t_node *head_a,
		size_t stack_a_size)
{
	int	min_node_position;

	set_positions(head_a);
	min_node_position = INT_MAX;
	get_min_node_position(head_a, &min_node_position);
	if ((size_t)min_node_position > stack_a_size / 2)
	{
		while ((size_t)min_node_position < stack_a_size)
		{
			min_node_position++;
			rra(&main->head_a, false);
		}
	}
	else
	{
		while (min_node_position)
		{
			min_node_position--;
			ra(&main->head_a, false);
		}
	}
}

void	start_sorting(t_program *main)
{
	push_b_until_three(main, main->stack_a_size);
	sort_three(&main->head_a);
	while (main->head_b)
	{
		set_targets(main);
		set_cost(main);
		find_best_move(main);
	}
	if (!stack_sorted(main->head_a))
		rotate_until_min_is_top(main, main->head_a, main->stack_a_size);
}
