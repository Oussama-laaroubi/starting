/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:45:47 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/10 00:50:54 by olaaroub         ###   ########.fr       */
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
    rotate(head_a);
    ft_printf("ra\n");
}
