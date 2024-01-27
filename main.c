/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/27 23:12:53 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*head;
	t_node	*tail;
	t_node 	*tmp;

	head = NULL;
	tail = NULL;
	if (ac == 1)
		return (0);
	fill_stack(av, &tail, &head);
	check_stack(&head);
	tmp = head;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	deallocate_stack(&head, &tail);
	free(tmp);
	tmp = NULL;
	system("leaks push_swap");
}
