/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:41:32 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/04 17:10:16 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *head)
{
	t_node	*tmp;
	int		cmp;

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
	if (head != NULL)
		iterator = head->next;
	while (iterator)
	{
		if (iterator->value < iterator->previous->value)
			return (false);
		iterator = iterator->next;
	}
	return (true);
}
