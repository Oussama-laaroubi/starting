/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/02 21:25:09 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*head_b;
	t_node	*head_a;
	char	**ptr;

	ptr = NULL;
	head_a = NULL;
	head_b = NULL;
	check_numbers(av, ac);
	fill_stack(av, &head_a, ptr);
	check_duplicates(&head_a);
	if (!stack_sorted(head_a))
	{
		if (stack_size(head_a) == 3)
			sort_three(&head_a);
		else if(stack_size(head_a) == 2)
			sa(&head_a);
		else
			start_sorting(&head_a, &head_b);
	}
	print_stack(head_a);
	deallocate_stack(&head_a);
	deallocate_stack(&head_b);
}
