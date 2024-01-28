/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/28 18:27:54 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*head;
	t_node	*tail;
	t_node	*tmp;
	char	**ptr;

	ptr = NULL;
	(void)ac;
	head = NULL;
	tail = NULL;
	check_numbers(av);
	fill_stack(av, &tail, &head, ptr);
	check_duplicates(&head);
	tmp = head;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	deallocate_stack(&head, &tail);
	free(tmp);
	tmp = NULL;
}
