/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:02:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/15 12:15:36 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	stack_size(t_node *head)
{
	t_node	*tmp;
	size_t	cmp;

	cmp = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		cmp++;
	}
	return (cmp);
}

void	append_last(t_node **head, int value)
{
	t_node	*new;
	t_node	*tail;

	tail = find_tail(*head);
	new = malloc(sizeof(t_node));
	if (new == NULL)
	{
		deallocate_stack(head);
		exit(1);
	}
	new->next = NULL;
	new->value = value;
	if (!*head)
		(*head) = new;
	else if (tail != NULL)
		tail->next = new;
}

void	deallocate_stack(t_node **head)
{
	t_node	*current;
	t_node	*tmp;

	if (head == NULL || *head == NULL)
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

t_node	*find_tail(t_node *head)
{
	t_node	*tmp;

	tmp = head;

	if (head == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
