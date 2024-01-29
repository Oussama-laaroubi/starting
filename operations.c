/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:36:14 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/29 14:27:38 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_node   **head)
{
	t_node	*tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return ;
	}
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->previous = (*head)->previous;
	(*head)->previous = tmp;
	if (tmp->next != NULL)
	{
		tmp->next->previous = *head;
	}
	tmp->next = *head;
	*head = tmp;
    ft_printf("sa\n");
}

void    ra(t_node   **head, t_node  **tail)
{
    t_node *top;

    top = (*head)->next;
    top->previous = NULL;
    (*tail)->next = *head;
    (*head)->next = NULL;
    (*head)->previous = *tail;
    (*tail) = (*head);
    (*head) = top;
    ft_printf("ra\n");
}