/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:45:47 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/11 15:39:21 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void rotate(node** head)
{
    node* tmp;
    node* tail;

    if(!*head)
        return;
    tail = find_tail(*head);
    tmp = (*head)->next;
    (*head)->next = NULL;
    tail->next = (*head);
    (*head) = tmp;
}

void    ra(node** head_a)
{
    if(!*head_a)
        return;
    rotate(head_a);
    ft_printf("ra\n");
}

void    rb(node** head_b)
{
    if(!*head_b)
        return;
    rotate(head_b);
    ft_printf("rb\n");
}

void    rr(t_program* main)
{
    if(!main->head_b || !main->head_a)
        return;
    rotate(&main->head_a);
    rotate(&main->head_b);
    ft_printf("rr\n");
}
