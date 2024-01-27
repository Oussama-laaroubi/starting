/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:39:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/27 11:10:56 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_stack(t_node **head, t_node **tail, char **ptr)
{
	int	k;

	k = 1;
	init(head, tail, atoi(ptr[0]));
	while (ptr[k] != NULL && ptr[k][0] != '\0')
	{
		append_beggining(head, atoi(ptr[k]));
		k++;
	}
}

void	fill_stack(char **av, t_node **head, t_node **tail)
{
	char	**ptr;
	int		k;
	int		first_time;
	int		index;

	ptr = NULL;
	k = 1;
	first_time = 1;
	while (av[k])
	{
		index = 0;
		ptr = ft_split(av[k], ' ');
		if (first_time == 1)
		{
			start_stack(head, tail, ptr);
		}
		while (ptr[index] && first_time == 2)
		{
			append_beggining(head, atoi(ptr[index]));
			index++;
		}
		first_time = 2;
		k++;
	}
}
