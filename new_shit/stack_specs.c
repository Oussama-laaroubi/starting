/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:41:32 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/11 11:43:51 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

size_t	stack_size(node *head)
{
	node	*tmp;
	size_t		cmp;

	cmp = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		cmp++;
	}
	return (cmp);
}

node	*max_node(node *head)
{
	node	*max;

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

node	*min_node(node *head)
{
	node	*min;

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

bool	stack_sorted(node *head)
{
	node	*iterator;

	iterator = NULL;
	while (head)
	{
		iterator = head->next;
		if (iterator->value < head->value)
			return (false);
		head = head->next;
	}
	return (true);
}
