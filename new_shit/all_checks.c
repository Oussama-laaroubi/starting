/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:22:37 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/09 23:58:57 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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

static int	check_digits(char **ptr)
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
				free(ptr[k]);
				free(ptr);
				return (0);
			}
			i++;
		}
		free(ptr[k]);
		k++;
	}
	return (1);
}

static int	check_int(char **ptr)
{
	int	i;
	int	k;

	i = 0;
	while (ptr[i])
	{
		if (ft_atol(ptr[i]) > 2147483647 || ft_atol(ptr[i]) < -2147483648)
		{
			k = 0;
			while (ptr[k])
			{
				free(ptr[k]);
				k++;
			}
			free(ptr);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_duplicates(node **head)
{
	node	*tmp;
	node	*next;

	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (next->value == tmp->value)
			{
				deallocate_stack(head);
				return (0);
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_args(char **av, int ac)
{
	char	**ptr;
	int		arg;

	if (ac < 2)
		return (0);
	arg = 1;
	while (av[arg])
	{
		ptr = ft_split(av[arg], ' ');
		if (!ptr || !ptr[0])
		{
			free(ptr);
			return (0);
		}
		if (!check_int(ptr))
			return (0);
		if (!check_digits(ptr))
			return (0);
		free(ptr);
		arg++;
	}
	return (1);
}

void	ft_error(char *error)
{
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(1);
}
