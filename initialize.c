/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:39:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/27 23:04:53 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_stack(t_node **tail, t_node **head, char **ptr)
{
	int	k;
	int f;

	k = 1;
	init(tail, head, atoi(ptr[0]));
	while (ptr[k] != NULL && ptr[k][0] != '\0')
	{
		append_last(tail, atoi(ptr[k]));
		k++;
	}

	f = 0;
	while (ptr[f])
	{
		free(ptr[f]);
		ptr[f] = NULL;
		f++;
	}
	free(ptr[f]);

}

void	fill_stack(char **av, t_node **tail, t_node **head)
{
	char	**ptr;
	int		k;
	bool	first_time;
	int		index;
	int		f;

	ptr = NULL;
	k = 1;
	first_time = true;
	while (av[k])
	{
		index = 0;
		ptr = ft_split(av[k], ' ');
		if (first_time == true)
		{
			start_stack(tail, head, ptr);
		}
		while (ptr[index] && first_time == false)
		{
			append_last(tail, atoi(ptr[index]));
			index++;
		}
		f = 0;
		while (ptr[f])
		{
			free(ptr[f]);
			ptr[f] = NULL;
			f++;
		}
		free(ptr[f]);
		first_time = false;
		k++;
	}
	free(ptr);
	ptr = NULL;
}
