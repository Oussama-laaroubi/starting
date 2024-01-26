/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:39:26 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/26 19:07:44 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	start_stack(node **head, node **tail, char **ptr)
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

void	fill_stack(char **av, node **head, node **tail)
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
		ptr = ft_split(av[k], ',');
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

// if(ac == 2)
// {
//     int i = 1;
//     ptr = ft_split(av[1], ' ');
//     int k = 0;
//     int count = 0;
//     while (ptr[k])
//     {
//         count++;
//         k++;
//     }

//     init(&head, &tail, atoi(ptr[0]));

//     while(i < count)
//     {
//         append_beggining(&head, atoi(ptr[i]));
//         i++;
//     }
//     while (head)
//     {
//         printf("%d\n", head->value);
//         head = head->next;
//     }
// }
// else
// {
//     int i = 2;

//     init(&head, &tail, atoi(av[1]));
//     while (i < ac)
//     {
//         append_beggining(&head, atoi(av[i]));
//         i++;
//     }

//     // swap(&head);
//     while (head)
//     {
//         printf("%d\n", head->value);
//         head = head->next;
//     }
// }