/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:02:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/12 20:21:11 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *error)
{
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(1);
}

void	append_last(t_node **head, int value)
{
	t_node	*new;
	t_node	*tail;

	tail = find_tail(*head);
	new = malloc(sizeof(t_node));
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

void	deallocate_stack(t_node **head)
{
	t_node	*current;
	t_node	*tmp;

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
