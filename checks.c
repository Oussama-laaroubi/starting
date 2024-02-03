/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:38:47 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/03 09:47:41 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

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
				k = 0;
				while(ptr[k])
				{
					free(ptr[k]);
					k++;
				}
				free(ptr);
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
	int	k;

	i = 0;
	while (ptr[i])
	{
		if (ft_atol(ptr[i]) > 2147483647 || ft_atol(ptr[i]) < -2147483648)
		{
			ft_putstr_fd("Error: Please enter an integer !!\n", 2);
			k = 0;
			while(ptr[k])
			{
				free(ptr[k]);
				k++;
			}
			free(ptr);
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
				deallocate_stack(head);
				exit(1);
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
}

void	check_numbers(char **av, int ac)
{
	char	**ptr;
	int		arg;
	int		k;

	if (ac == 0)
		exit (1);
	if (ac < 2)
	{
		ft_putstr_fd("Invalid number of arguments !!", 2);
		exit(1);
	}
	arg = 1;
	while (av[arg])
	{
		k = 0;
		ptr = ft_split(av[arg], ' ');
		check_int(ptr);
		check_digits(ptr);
		// while(ptr[k])
		// {
		// 	free(ptr[k]);
		// 	k++;
		// }
		free(ptr);
		arg++;
	}
}
