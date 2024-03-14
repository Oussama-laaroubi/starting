/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:29:49 by olaaroub          #+#    #+#             */
/*   Updated: 2024/03/02 16:36:06 by olaaroub         ###   ########.fr       */
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

int* sortedSquares(int* nums, int numsSize) {
    for(int i = 0; i < numsSize ; i++){
        nums[i] *= nums[i];
    }
    quicksort(nums, 0, numsSize);
    return nums;
}

int	main(void)
{
	int nums[] = {-4,-1,0,3,10};

	sortedSquares(nums, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

}
