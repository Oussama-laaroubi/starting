/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/31 16:23:29 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*head;
	t_node	*tail;
	char	**ptr;
	t_node	*tmp2;
	t_node	*head_b;

	ptr = NULL;
	(void)ac;
	head = NULL;
	tail = NULL;
	head_b = NULL;
	check_numbers(av);
	fill_stack(av, &tail, &head, ptr);
	check_duplicates(&head);
	// rra(&head, &tail);
	// sa(&head);
	// ra(&head, &tail);
	// pb(&head_b, &head);
	// pb(&head_b, &head);
	pb(&head, &head_b);
	pb(&head, &head_b);
	// printf("tails content is  %d\n", find_tail(head)->value);
	// ss(&head, &head_b);
	// sb(&head_b);


	tmp2 = head;
	while (tmp2)
	{
		ft_printf("stack aa %d\n", tmp2->value);
		tmp2 = tmp2->next;
	}
	while (head_b)
	{
		ft_printf("stack bb %d\n", head_b->value);
		head_b = head_b->next;
	}
	t_node *tail_b = find_tail(head_b);
	deallocate_stack(&head_b, &tail_b);
	deallocate_stack(&head, &tail);
	free(tmp2);
	// system("leaks push_swap");
}
