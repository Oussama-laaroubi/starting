/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/26 19:12:40 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	node	*head;
	node	*tail;

	head = NULL;
	tail = NULL;
	if (ac == 1)
		return (0);
	fill_stack(av, &head, &tail);
	while (tail)
	{
		printf("%d\n", tail->value);
		tail = tail->previous;
	}
}
