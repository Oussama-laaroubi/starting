/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:16:41 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/02 15:51:34 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sort_l7za9(t_node** head_a, t_node** head_b)
{
    int stack_a_size;

    stack_a_size = stack_size(*head_a);
    if(stack_a_size-- > 3 && !stack_sorted(*head_a))
        pb(head_b, head_a);
    if(stack_a_size-- > 3 && !stack_sorted(*head_a))
        pb(head_b, head_a);
    while (stack_a_size-- > 3 && !stack_sorted(*head_a))
    {
        configure_nodes(*head_a, *head_b);
        fill_stack_b(head_a, head_b);
    }
    sort_three(head_a);
    while (*head_b)
    {
        configure_nodes(*head_a, head_b);
        fill_back_a(head_a, head_b);
    }
    current_index(*head_a);
    min_on_top(head_a);
}
