/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:20:17 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/08 23:50:35 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void    ft_fill_stack(t_program* main,char** av)
{
    char** ptr;
    int k;
    int index;

    k =1;
    while(main->ac)
    {
        index = 0;
        ptr = ft_split(av[k], ' ');
        while(ptr[index])
        {
            append_last(&main->head_a, ft_atoi(ptr[index]));
            // free(ptr[index]);
            index++;
        }
        // free(ptr);
        main->ac--;
        k++;
    }
    main->filled = true;
}

static void    ft_fill_args(t_program* main, char *av)
{
    char** ptr;
    int k;

    k = 0;
    ptr = ft_split(av, ' ');
    if(!ptr)
        exit(1);
    while(ptr[k])
    {
        append_last(&main->head_a, ft_atoi(ptr[k]));
        // free(ptr[k]);
        k++;
    }
    // free(ptr);
    main->av = ptr;
    main->ac = k;
    main->filled =  true;

}

int main(int ac, char **av)
{
    t_program   main;

    main.filled = false;
    main.head_a = NULL;
    if(ac == 2)
        ft_fill_args(&main, av[1]);
    if(!main.filled)
    {
        main.ac = ac - 1;
        ft_fill_stack(&main, av);
    }
    node* tmp  = main.head_a;
    while(tmp)
    {
        printf("value is %d\n", tmp->value);
        tmp = tmp->next;
    }

}
