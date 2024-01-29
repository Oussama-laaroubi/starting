/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/29 14:27:24 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*head;
	t_node	*tail;
	// t_node	*tmp;
	char	**ptr;
	t_node *tmp2;

	ptr = NULL;
	(void)ac;
	head = NULL;
	tail = NULL;
	check_numbers(av); // checks if the numbers are valid integers
	fill_stack(av, &tail, &head, ptr);
	check_duplicates(&head); // checks if there is dubplicate numbers in the stack

	sa(&head);
	ra(&head, &tail);

	tmp2 = head;

	while (tmp2)
	{
		ft_printf("%d\n", tmp2->value);
		tmp2 = tmp2->next;
	}

	deallocate_stack(&head, &tail);
	// free(tmp);
	free(tmp2);
	system("leaks push_swap");
}
