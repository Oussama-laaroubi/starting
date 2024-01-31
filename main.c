/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/31 22:30:54 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*head;
	t_node	*tail;
	char	**ptr;
	t_node	*tmp_a;
	t_node	*tmp_b;
	t_node	*head_b;
	t_node	*tail_b;

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
	sb(&head_b);
	pa(&head_b, &head);
	pa(&head_b, &head);
	sa(&head);
	// printf("tails content is  %d\n", find_tail(head)->value);
	// ss(&head, &head_b);
	// sb(&head_b);
	tmp_a = head;
	while (tmp_a)
	{
		ft_printf("stack aa %d\n", tmp_a->value);
		tmp_a = tmp_a->next;
	}
	tmp_b = head_b;
	while (tmp_b)
	{
		ft_printf("stack bb %d\n", tmp_b->value);
		tmp_b = tmp_b->next;
	}
	tail_b = find_tail(head_b);
	deallocate_stack(&head_b, &tail_b);
	deallocate_stack(&head, &tail);
	// system("leaks push_swap");
}
