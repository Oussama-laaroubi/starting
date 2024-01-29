/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:02:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/29 14:26:36 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_node **tail, t_node **head, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
	{
		exit(2);
		return ;
	}
	new->value = value;
	new->previous = NULL;
	new->next = NULL;
	*head = new;
	*tail = new;
}

void	append_last(t_node **tail, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
	{
		exit(1);
		return ;
	}
	new->value = value;
	new->previous = *tail;
	new->next = NULL;
	if (*tail != NULL)
	{
		(*tail)->next = new;
	}
	*tail = new;
}

void	deallocate_stack(t_node **head, t_node **tail)
{
	t_node	*curr;

	curr = *head;
	if (*head == NULL)
		return ;
	while (curr->next)
	{
		curr = curr->next;
		free(curr->previous);
	}
	free(curr);
	curr = NULL;
	*tail = NULL;
	*head = NULL;
}
