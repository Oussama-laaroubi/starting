/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:25:21 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/01 15:30:43 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sort_three(t_node** head)
{
    t_node* max;

    max = max_node(*head);
    if(*head == max)
        ra(head);
    else if((*head)->next == max)
        rra(head);
    if((*head)->value > (*head)->next->value)
        sa(head);
}
