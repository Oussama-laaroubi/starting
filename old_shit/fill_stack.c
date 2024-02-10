/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:39:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/01 15:46:33 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_stack(t_node **tail, t_node **head, char **ptr)
{
	int	k;

	k = 1;
	init(tail, head, ft_atoi(ptr[0]));
	while (ptr[k] != NULL && ptr[k][0] != '\0')
	{
		append_last(tail, ft_atoi(ptr[k]));
		free(ptr[k]);
		k++;
	}
}

void	fill_stack(char **av, t_node **head, char **ptr)
{
	int		k;
	bool	first_time;
	int		index;
	t_node	*tail;

	tail = find_tail(*head);
	k = 1;
	first_time = true;
	while (av[k])
	{
		index = 0;
		ptr = ft_split(av[k], ' ');
		if (first_time == true)
			start_stack(&tail, head, ptr);
		while (ptr[index] && first_time == false)
		{
			append_last(&tail, ft_atoi(ptr[index]));
			free(ptr[index]);
			index++;
		}
		free(ptr[index]);
		free(ptr);
		first_time = false;
		k++;
	}
}
