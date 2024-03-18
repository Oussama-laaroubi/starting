/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:41:57 by olaaroub          #+#    #+#             */
/*   Updated: 2024/03/18 01:10:32 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = *head;
	tail = find_tail(*head);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	tail->next = (*head);
	*head = tail;
}

void	rra(t_node **head_a, bool print)
{
	if (!*head_a || stack_size(*head_a) == 1)
		return ;
	reverse_rotate(head_a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_node **head_b, bool print)
{
	if (!*head_b || stack_size(*head_b) == 1)
		return ;
	reverse_rotate(head_b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_program *main, bool print)
{
	if (!main->head_a || !main->head_b)
		return ;
	if (main->stack_a_size == 1 || main->stack_b_size == 1)
		return ;
	reverse_rotate(&main->head_a);
	reverse_rotate(&main->head_b);
	if (!print)
		ft_printf("rrr\n");
}

void	rrr_bonus(t_checker *checker)
{
	if (!checker->head_a || !checker->head_b)
		return ;
	if (checker->stack_a_size == 1 || checker->stack_b_size == 1)
		return ;
	reverse_rotate(&checker->head_a);
	reverse_rotate(&checker->head_b);
}
