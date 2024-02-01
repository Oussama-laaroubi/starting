/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_of_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:33:19 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/01 15:35:14 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
