/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:51:08 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/11 12:06:10 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static void push_b(t_program* main)
{
    node* tmp;

    if(!main->head_a)
        return;
    tmp = main->head_a->next;
    main->head_a->next = main->head_b;
    main->head_b = main->head_a;
    main->head_a = tmp;

}

static void push_a(t_program* main)
{
    node* tmp;

    if(!main->head_b)
        return;
    tmp = main->head_b->next;
    main->head_b->next = main->head_a;
    main->head_a = main->head_b;
    main->head_b = tmp;
}

void    pa(t_program* main)
{
    if(!main->head_b)
        return;
    push_a(main);
    main->stack_b_size--;
    main->stack_a_size++;
    ft_printf("pa\n");
}

void    pb(t_program* main)
{
    if(!main->head_a)
        return;
    push_b(main);
    main->stack_a_size--;
    main->stack_b_size++;
    ft_printf("pb\n");
}
