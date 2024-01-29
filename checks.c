/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:38:47 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/29 11:48:37 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_digits(char **ptr)
{
	int	k;
	int	i;

	k = 0;
	while (ptr[k])
	{
		i = 0;
		if (ptr[k][0] == '-')
			i = 1;
		while (ptr[k][i])
		{
			if (!ft_isdigit(ptr[k][i]))
			{
				printf("Error: Please enter an integer cc !!\n");
				exit(-1);
			}
			i++;
		}
		free(ptr[k]);
		k++;
	}
}

static void	check_int(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ft_atol(ptr[i]) > 2147483647 || ft_atol(ptr[i]) < -2147483648)
		{
			printf("Error: Please enter an integer !!\n");
			exit(1);
		}
		i++;
	}
}

void	check_duplicates(t_node **head)
{
	t_node	*tmp;
	t_node	*next;

	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (next->value == tmp->value)
			{
				printf("Error: Duplicates are not allowed !!\n");
				exit(1);
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
	free(tmp);
	tmp = NULL;
	free(next);
	next = NULL;
}

void	check_numbers(char **av)
{
	char	**ptr;
	int		arg;

	arg = 1;
	while (av[arg])
	{
		ptr = ft_split(av[arg], ' ');
		check_int(ptr);
		check_digits(ptr);
		free(ptr);
		arg++;
	}
}
