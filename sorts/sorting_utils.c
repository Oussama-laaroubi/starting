/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:38:34 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/02 19:12:29 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*lowest_cost(t_node *head)
{
	t_node	*lowest_cost_node;

	if (!head)
		return (NULL);
	lowest_cost_node = NULL;
	while (head)
	{
		if (head->cheapest == true)
		{
			lowest_cost_node = head;
			break ;
		}
		head = head->next;
	}
	return (lowest_cost_node);
}
void    rotate_both(t_node** head_a, t_node** head_b, t_node* lowes_node)
{
    while ((*head_b) != lowes_node->target && (*head_a) != lowes_node)
        rr(head_a, head_b);
    current_index(*head_a);
    current_index(*head_b);
}
void    r_rotate_both(t_node** head_a, t_node** head_b, t_node* lowest_node)
{
    while(*head_b != lowest_node->target && *head_a != lowest_node)
        rrr(head_a, head_b);
    current_index(*head_a);
    current_index(*head_b);
}
void    adjust_top(t_node** head, t_node* lowest_node, char current_stack)
{
    while(*head != lowest_node)
    {
        if(current_stack == 'a')
        {
            if(lowest_node->above_median == false)
                rra(head);
            else if(lowest_node->above_median == true)
                ra(head);
        }
        else if(current_stack == 'b')
        {
            if(lowest_node->above_median == false)
                rrb(head);
            else if(lowest_node->above_median == true)
                rb(head);
        }
    }
}
