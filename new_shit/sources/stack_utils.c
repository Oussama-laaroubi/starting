/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:02:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/12 19:08:35 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append_last(node **head, int value)
{
	node	*new;
	node	*tail;

	tail = find_tail(*head);
	new = malloc(sizeof(node));
	if (new == NULL)
		exit(1);
	new->value = value;
	new->next = NULL;
	new->index = DEF;
	if (!*head)
		(*head) = new;
	else if (tail != NULL)
		tail->next = new;
}

void	deallocate_stack(node **head)
{
	node	*current;
	node	*tmp;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	head = NULL;
}

node	*find_tail(node *head)
{
	node	*tmp;

	tmp = head;
	if (head == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
