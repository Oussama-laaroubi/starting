/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:41:32 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/19 15:27:31 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	stack_size(t_node *head)
{
	t_node	*tmp;
	size_t	cmp;

	cmp = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		cmp++;
	}
	return (cmp);
}

t_node	*max_node(t_node *head)
{
	t_node	*max;

	if (!head)
		return (NULL);
	max = head;
	while (head)
	{
		if (head->value > max->value)
			max = head;
		head = head->next;
	}
	return (max);
}

t_node	*min_node(t_node *head)
{
	t_node	*min;

	if (!head)
		return (NULL);
	min = head;
	while (head)
	{
		if (head->value < min->value)
			min = head;
		head = head->next;
	}
	return (min);
}

bool	stack_sorted(t_node *head)
{
	t_node	*iterator;

	iterator = NULL;
	while (head)
	{
		if (head->next)
			iterator = head->next;
		if (iterator && iterator->value < head->value)
			return (false);
		head = head->next;
	}
	return (true);
}
