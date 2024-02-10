/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:51:08 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/10 02:05:55 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void push_b(node** head_a, node** head_b)
{
    node* tmp;

    if(!*head_a)
        return;
    tmp = (*head_a)->next;
    (*head_a)->next = (*head_b);
    (*head_b) = (*head_a);
    (*head_a) = tmp;
}

static void push_a(node** head_a, node** head_b)
{
    node* tmp;

    if(!*head_b)
        return;
    tmp = (*head_b)->next;
    (*head_b)->next = (*head_a);
    (*head_a) = (*head_b);
    (*head_b) = tmp;
}

void    pa(node** head_a, node** head_b)
{
    if(!*head_b)
        return;
    push_a(head_a, head_b);
    ft_printf("pa\n");
}

void    pb(node** head_a, node** head_b)
{
    if(!*head_a)
        return;
    push_b(head_a, head_b);
    ft_printf("pb\n");
}
