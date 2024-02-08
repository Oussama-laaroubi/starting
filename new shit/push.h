/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:20:43 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/08 18:24:38 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
#define PUSH_H

typedef struct s_node
{
    int value;
    struct s_node *next;
}   t_node;

typedef struct s_program
{
    t_node *head_a;
    t_node *head_b;
    int stack_b_size;
    int stack_a_size;
}   t_program;

#endif