/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:36:14 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/29 22:11:07 by olaaroub         ###   ########.fr       */
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
	if (*head == NULL || (*head)->next == NULL)
	{
		return ;
	}

	top = (*head)->next;
	(*tail)->next = *head;
	(*head)->next = NULL;
	top->previous = NULL;
	(*head)->previous = *tail;
	(*tail) = (*head);
	(*head) = top;
	ft_printf("ra\n");
}
// void rra(t_node **head, t_node **tail) {
//     t_node *bottom;

//     if (*head == NULL || (*head)->next == NULL) {
//         return;
//     }

// 	bottom = (*tail)->previous;

//     // Adjusting pointers to make the last node the first node
//     bottom->next = NULL;
//     bottom->previous = NULL;
//     (*tail)->previous = *head;
//     (*tail)->next = NULL;
//     (*head)->next = *tail;
//     (*head)->previous = bottom;
//     (*head) = (*tail);
//     (*tail) = bottom;

//     printf("rra\n");
// }


void	rra(t_node **head, t_node **tail)
{
	t_node	*bottom;

	if (*head == NULL || (*head)->next == NULL)
	{
		return ;
	}

	bottom = (*tail)->previous;
	bottom->next = NULL;
	(*tail)->previous = NULL;
	(*head)->previous = (*tail);
	if((*head) != NULL)
		(*tail)->next = (*head);
	(*head) = (*tail);
	(*tail) = bottom;

	ft_printf("rra\n");
}

void    pb(t_node** head_b, t_node **head)
{
    t_node* tmp;
	if (*head == NULL || (*head)->next == NULL)
	{
		return ;
	}
    tmp = (*head)->next;
	printf("im here");
    append_beginning(head_b, (*head)->value );
    tmp->previous = NULL;
    (*head) = tmp;
	ft_printf("pb\n");
}
