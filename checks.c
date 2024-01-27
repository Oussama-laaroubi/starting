/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:38:47 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/27 23:01:31 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicates(t_node **head)
{
	t_node	*tmp;
	t_node	*next;

	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (next->value == tmp->value)
			{
				ft_printf("Error: Duplicates not allowed");
				exit(1);
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
	free(tmp);
	tmp = NULL;
	free(next);
	next = NULL;
}

void	check_stack(t_node **head)
{
	check_duplicates(head);
}
