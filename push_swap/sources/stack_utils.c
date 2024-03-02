/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:02:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/03/01 18:10:21 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_when_error(char **ptr)
{
	int	k;

	k = 0;
	while (ptr[k])
		free(ptr[k++]);
	free(ptr);
}

void	ft_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
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
		ft_error(ERROR_MESSAGE);
	}
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
