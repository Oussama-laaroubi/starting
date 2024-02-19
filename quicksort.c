/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:29:49 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/19 15:30:26 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	partitioning(int *array, int start, int end)
{
	int	pIndex;
	int	pivot;

	pivot = array[end];
	pIndex = start;
	for (int i = start; i < end; i++)
	{
		if (array[i] <= pivot)
			swap(&array[i], &array[pIndex++]);
	}
	swap(&array[pIndex], &array[end]);
	return (pIndex);
}

void	quicksort(int *array, int start, int end)
{
	int	pIndex;

	if (start < end)
	{
		pIndex = partitioning(array, start, end);
		quicksort(array, start, pIndex - 1);
		quicksort(array, pIndex + 1, end);
	}
}

int	main(void)
{
	int	array[] = {4, 1, 0, 9, -1};
	quicksort(array, 0, 4);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}
	return (0);
}
