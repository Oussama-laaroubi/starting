/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:01:02 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/26 15:59:24 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init(node **head, node **tail, int value)
{
	node	*new;

	new = malloc(sizeof(node));
	if (new == NULL)
	{
		exit(2);
		return ;
	}
	new->value = value;
	new->previous = NULL;
	new->next = NULL;
	*head = new;
	*tail = new;
}

static void	swap(node **head)
{
	node	*tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return ;
	}
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->previous = (*head)->previous;
	(*head)->previous = tmp;
	if (tmp->next != NULL)
	{
		tmp->next->previous = *head;
	}
	tmp->next = *head;
	*head = tmp;
}

static void	append_beggining(node **head, int value)
{
	node	*new;

	new = malloc(sizeof(node));
	if (new == NULL)
	{
		exit(1);
		return ;
	}
	new->value = value;
	new->previous = NULL;
	new->next = *head;
	if (*head != NULL)
	{
		(*head)->previous = new;
	}
	*head = new;
}

static int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

int	main(int ac, char **av)
{
	node	*head;
	node	*tail;
	char	**ptr;
	int		i;
	int		k;
	int		count;
	int		i;

	head = NULL;
	tail = NULL;
	ptr = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		i = 1;
		ptr = ft_split(av[1], ' ');
		k = 0;
		count = 0;
		while (ptr[k])
		{
			count++;
			k++;
		}
		init(&head, &tail, atoi(ptr[0]));
		while (i < count)
		{
			append_beggining(&head, atoi(ptr[i]));
			i++;
		}
		while (head)
		{
			printf("%d\n", head->value);
			head = head->next;
		}
	}
	else
	{
		i = 2;
		init(&head, &tail, atoi(av[1]));
		while (i < ac)
		{
			append_beggining(&head, atoi(av[i]));
			i++;
		}
		// swap(&head);
		while (head)
		{
			printf("%d\n", head->value);
			head = head->next;
		}
	}
}
