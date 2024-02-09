/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:20:43 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/08 23:50:07 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
#define PUSH_H

#include "stdbool.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

typedef struct struct_node
{
    int value;
    struct struct_node *next;
}   node;

typedef struct s_program
{
    node *head_a;
    node *head_b;
    int stack_b_size;
    int stack_a_size;
    bool    filled;
    char** av;
    int ac;
}   t_program;

void	append_last(node** head, int value);
node	*find_tail(node *head);


#endif