/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_other2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:51:18 by astefans          #+#    #+#             */
/*   Updated: 2024/07/10 15:53:32 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(long *array, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
}

int	partition(long *array, int low, int high)
{
	long	pivot;
	int		i;
	int		j;
	long	temp;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	return (i + 1);
}
