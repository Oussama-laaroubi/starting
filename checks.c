/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:38:47 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/01 11:52:29 by olaaroub         ###   ########.fr       */
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
				ft_putstr_fd("Error: Please enter an integer cc !!\n", 2);
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
			ft_putstr_fd("Error: Please enter an integer !!\n", 2);
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
				ft_putstr_fd("Error: Duplicates are not allowed !!\n", 2);
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

void	check_numbers(char **av, int ac)
{
	char	**ptr;
	int		arg;

	if (ac < 2)
	{
		ft_putstr_fd("Invalid number of arguments !!", 2);
		exit(1);
	}
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
