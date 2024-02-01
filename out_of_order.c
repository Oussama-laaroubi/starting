/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_of_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:33:19 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/01 14:14:21 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_sorted(t_node *head)
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

void	stack_sorted(t_node *head)
{
	if (!is_sorted(head))
		ft_printf("stack is not sorted\n");
	else if (is_sorted(head) == true)
		ft_printf("stack is sorted\n");
}
