/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:41:57 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/10 18:49:34 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void	reverse_rotate(node **head)
{
	node	*tmp;
	node	*tail;

	if (!(*head))
		return ;
	tmp = *head;
	tail = find_tail(*head);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	tail->next = (*head);
	*head = tail;
}

void	rra(node **head_a)
{
	if (!*head_a)
		return ;
	reverse_rotate(head_a);
	ft_printf("rra\n");
}

void	rrb(node **head_b)
{
	if (!*head_b)
		return ;
	reverse_rotate(head_b);
	ft_printf("rrb\n");
}

void    rrr(node** head_a, node** head_b)
{
    if(!*head_a || !*head_b)
        return;
    reverse_rotate(head_a);
    reverse_rotate(head_b);
    ft_printf("rrr\n");
}
