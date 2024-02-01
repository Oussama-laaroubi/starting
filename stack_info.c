/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:41:32 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/01 18:40:49 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *head)
{
	int	cmp;

	cmp = 0;
	while (head)
	{
		head = head->next;
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
