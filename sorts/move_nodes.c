/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:33:45 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/02 21:29:44 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static void    fill_stack_b(t_node** head_a, t_node** head_b)
{
    t_node *lowest_node;

    lowest_node = lowest_cost(*head_a);
    if(lowest_node->above_median && lowest_node->target->above_median)
        rotate_both(head_a, head_b, lowest_node);
    else if(!(lowest_node->above_median) && !(lowest_node->target->above_median))
        r_rotate_both(head_a, head_b, lowest_node);
    adjust_top(head_a, lowest_node, 'a');
    adjust_top(head_b, lowest_node->target, 'b');
    pb(head_b, head_a);
}

static void fill_back_a(t_node** head_a, t_node** head_b)
{
    adjust_top(head_a, (*head_b)->target, 'a');
    pa(head_a, head_b);
}

static  void refresh_a(t_node** head_a)
{
    while((*head_a)->value != min_node(*head_a)->value)
    {
        if(min_node(*head_a)->above_median == true)
            ra(head_a);
        else if (min_node(*head_a)->above_median == false)
            rra(head_a);
    }
}

void    start_sorting(t_node** head_a, t_node** head_b)
{
    int stack_a_size;

    stack_a_size = stack_size(*head_a);
    if(stack_a_size-- > 3 && !stack_sorted(*head_a))
        pb(head_b, head_a);
    if(stack_a_size-- > 3 && !stack_sorted(*head_a))
        pb(head_b, head_a);
    while (stack_a_size-- > 3 && !stack_sorted(*head_a))
    {
        configure_nodes_a(*head_a, *head_b);
        fill_stack_b(head_a, head_b);
    }
    sort_three(head_a);
    while (*head_b)
    {
        configure_nodes_b(*head_a, *head_b);
        fill_back_a(head_a, head_b);
    }
    current_index(*head_a);
    refresh_a(head_a);
}
