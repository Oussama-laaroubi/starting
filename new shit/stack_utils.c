/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:02:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/08 23:49:49 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	init(node **tail, node **head, int value)
{
	node	*new;

	new = malloc(sizeof(node));
	if (new == NULL)
	{
		exit(1);
		return ;
	}
	new->value = value;
	new->next = NULL;
	*head = new;
	*tail = new;
}

void	append_last(node** head, int value)
{
	node	*new;
	node	*tail;

	tail = find_tail(*head);
	new = malloc(sizeof(node));
	if (new == NULL)
		exit(1);
	new->value = value;
	new->next = NULL;
	if (tail != NULL)
	{
		tail->next = new;
	}
	tail = new;
}

void	append_beginning(node **head, int value)
{
	node	*new;

	new = malloc(sizeof(node));
	if (new == NULL)
	{
		exit(1);
		return ;
	}
	new->value = value;
	new->next = *head;
	*head = new;
}

// void	deallocate_stack(node **head)
// {
// 	node	*curr;
// 	node	*tail;

// 	curr = *head;
// 	tail = find_tail(*head);
// 	if (*head == NULL)
// 		return ;
// 	while (curr->next)
// 	{
// 		curr = curr->next;
// 		free(curr->previous);
// 	}
// 	free(curr);
// 	curr = NULL;
// 	tail = NULL;
// 	*head = NULL;
// }

node	*find_tail(node *head)
{
	if (head == NULL)
		return (0);
	while (head->next != NULL)
		head = head->next;
	return (head);
}
