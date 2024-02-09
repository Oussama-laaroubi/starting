/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:20:06 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/09 23:59:51 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static node	*lowest_node(node *head)
{
	node	*min;
	int		lowest_val;

	if (!head)
		return (NULL);
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

void	ft_indexing(t_program *main)
{
	node	*min_node;
	node	*tmp;
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
