/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:47:07 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/14 23:18:26 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int  main()
{
    char *ptr;

    ptr = get_next_line(0);
    while (ptr)
    {
        ft_printf("%s", ptr);
        free(ptr);
        ptr = get_next_line(0);
    }
}
