/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:47:07 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/15 19:18:53 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	ft_fill_stack(t_checker *main, char **av)
{
	char	**ptr;
	int		k;
	int		index;

	k = 1;
	while (av[k])
	{
		index = 0;
		ptr = ft_split(av[k], ' ');
		if (!ptr)
			exit(1);
		while (ptr[index])
		{
			append_last(&main->head_a, ft_atoi(ptr[index]));
			free(ptr[index]);
			index++;
		}
		free(ptr);
		k++;
	}
	main->stack_a_size = stack_size(main->head_a);
	main->stack_b_size = 0;
	main->head_b = NULL;
}

int main(int ac, char** av)
{
    // t_checker  checker_main;

	// checker_main.head_a = NULL;
    char *ptr;
    (void)ac;
	(void)av;
    ptr = get_next_line(0);
	char* ptr2;
	ptr2 = ptr;
	// printf("=== ptr2 ===%s\n", ptr);
	// 	{
	// 		printf("not equal");
	// 		return 0;
	// 	}
	// printf("==here\n===\n\n");
	// else
		// ft_fill_stack(&checker_main, av);
    // while (ptr)
    // {
    //     ft_printf("%s", ptr);
    //     free(ptr);
    //     ptr = get_next_line(0);
    // }

    // t_node* tmp = checker_main.head_a;
    // ft_printf("\n===== checker stack =====\n");
    // while(tmp)
    // {
    //     ft_printf(" value == %d\n", tmp->value);
    //     tmp = tmp->next;
    // }
    // deallocate_stack(&checker_main.head_a);
}
