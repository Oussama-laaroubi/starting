/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:41:32 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/01 15:11:45 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
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
int	stack_size(t_node* head)
{
	int cmp;

	cmp = 0;
	while(head)
	{
		head = head->next;
		cmp++;
	}
	return cmp;
}

t_node	*max_node(t_node *head)
{
	t_node* max;

	if(!head)
		return NULL;
	max = head;
	while(head)
	{
		if(head->value > max->value)
			max = head;
		head = head->next;
	}
	return max;
}
