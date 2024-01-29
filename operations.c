/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:36:14 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/29 19:04:18 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head)
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

void	ra(t_node **head, t_node **tail)
{
	t_node	*top;

	top = (*head)->next;
	top->previous = NULL;
	(*tail)->next = *head;
	(*head)->next = NULL;
	(*head)->previous = *tail;
	(*tail) = (*head);
	(*head) = top;
	ft_printf("ra\n");
}

void	rra(t_node **head, t_node **tail)
{
	t_node	*bottom;

	bottom = (*tail)->previous;
	bottom->next = NULL;
	(*head)->previous = (*tail);
	(*tail)->next = (*head);
	(*tail)->previous = NULL;
	(*head) = (*tail);
	(*tail) = bottom;
	ft_printf("rra\n");
}

void    pb(t_node** head_b, t_node **head)
{
    t_node* tmp;

    tmp = (*head)->next;
	printf("im here");
    append_beginning(head_b, (*head)->value );
    tmp->previous = NULL;
    (*head) = tmp;
}
