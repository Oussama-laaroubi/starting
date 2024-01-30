/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:36:14 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/31 00:33:36 by olaaroub         ###   ########.fr       */
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
void	sb(t_node **head_b)
{
	t_node	*tmp;

	if (*head_b == NULL || (*head_b)->next == NULL)
	{
		return ;
	}
	tmp = (*head_b)->next;
	(*head_b)->next = tmp->next;
	tmp->previous = (*head_b)->previous;
	(*head_b)->previous = tmp;
	if (tmp->next != NULL)
	{
		tmp->next->previous = *head_b;
	}
	tmp->next = *head_b;
	*head_b = tmp;
	ft_printf("sa\n");
}

void	ra(t_node **head, t_node **tail)
{
	t_node	*top;

	if (*head == NULL)
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
void	rb(t_node **head_b, t_node **tail)
{
	t_node	*top;

	if (*head_b == NULL)
	{
		return ;
	}
	top = (*head_b)->next;
	(*tail)->next = *head_b;
	(*head_b)->next = NULL;
	top->previous = NULL;
	(*head_b)->previous = *tail;
	(*tail) = (*head_b);
	(*head_b) = top;
	ft_printf("ra\n");
}

void	rra(t_node **head, t_node **tail)
{
	t_node	*bottom;

	if (*head == NULL)
	{
		return ;
	}
	bottom = (*tail)->previous;
	bottom->next = NULL;
	(*tail)->previous = NULL;
	(*head)->previous = (*tail);
	if ((*head) != NULL)
		(*tail)->next = (*head);
	(*head) = (*tail);
	(*tail) = bottom;
	ft_printf("rra\n");
}

void	rrb(t_node **head_b, t_node **tail)
{
	t_node	*bottom;

	if (*head_b == NULL)
	{
		return ;
	}
	bottom = (*tail)->previous;
	bottom->next = NULL;
	(*tail)->previous = NULL;
	(*head_b)->previous = (*tail);
	if ((*head_b) != NULL)
		(*tail)->next = (*head_b);
	(*head_b) = (*tail);
	(*tail) = bottom;
	ft_printf("rra\n");
}

void	pb(t_node **head_b, t_node **head)
{
	t_node	*tmp;

	if (*head == NULL)
	{
		return ;
	}
	if ((*head)->next == NULL)
		tmp = *head;
	tmp = (*head)->next;
	// printf("im here");
	append_beginning(head_b, (*head)->value);
	// tmp->previous = NULL;
	(*head) = tmp;
	ft_printf("pb\n");
}

void	pa(t_node **head_b, t_node **head)
{
	t_node	*tmp;

	if (*head_b == NULL)
		return ;
	if ((*head_b)->next == NULL)
		tmp = *head_b;
	tmp = (*head_b)->next;
	// printf("im here");
	append_beginning(head, (*head_b)->value);
	// tmp->previous = NULL;
	(*head_b) = tmp;
	ft_printf("pa\n");
}
void	ss(t_node **head, t_node **head_b)
{
	sa(head);
	sb(head_b);
	ft_printf("ss\n");
}
void	rr(t_node **head, t_node **head_b)
{
	t_node *tail = find_tail(*head);
	t_node *tail_b = find_tail(*head_b);
	ra(head, &tail);
	rb(head_b, &tail_b);
	ft_printf("rr\n");
}