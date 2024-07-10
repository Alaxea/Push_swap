/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:36:41 by astefans          #+#    #+#             */
/*   Updated: 2024/07/08 13:02:59 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_stack(long *array, int *stack_size)
{
	quicksort(array, 0, stack_size[0] - 1);
}
//quick sort from sort_other2//

void	swap_stack_a_first(long *copy, long *copy_swap_stack_a,
	long *stack_a, int *num_in_a)
{
	int	i;

	i = 0;
	while (i < num_in_a[0])
	{
		copy[i] = stack_a[i];
		copy_swap_stack_a[i] = stack_a[i];
		i++;
	}
}

void	swap_stack_a_second(long *copy, long *copy_swap_stack_a,
	long *stack_a, int *num_in_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < num_in_a[1])
	{
		j = 0;
		while (j < num_in_a[0])
		{
			if (copy_swap_stack_a[i] == copy[j])
				stack_a[i] = j;
			j++;
		}
		i++;
	}
}

void	swap_stack_a_third(long *stack_a, long *stack_b,
	int *num_in_a, int *num_in_b)
{
	int	max_num;
	int	max_bits;
	int	loop_through[2];

	max_num = num_in_a[1] - 1;
	max_bits = 0;
	loop_through[0] = 0;
	loop_through[1] = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (loop_through[0] < max_bits)
	{
		loop_through[1] = 0;
		while (loop_through[1] < num_in_a[0])
		{
			if (((stack_a[0] >> loop_through[0]) & 1) == 1)
				rotate_stack_a(stack_a, num_in_a);
			else
				push_stack_b(stack_a, stack_b, num_in_a, num_in_b);
			++loop_through[1];
		}
		while (*num_in_b != 0)
			push_stack_a(stack_a, stack_b, num_in_a, num_in_b);
		++loop_through[0];
	}
}

void	sort_other(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b)
{
	long	*copy;
	long	*copy_swap_stack_a;

	copy = (long *)malloc(num_in_a[0] * sizeof(long));
	copy_swap_stack_a = (long *)malloc(num_in_a[0] * sizeof(long));
	swap_stack_a_first(copy, copy_swap_stack_a, stack_a, num_in_a);
	array_stack(copy, num_in_a);
	swap_stack_a_second(copy, copy_swap_stack_a, stack_a, num_in_a);
	free(copy);
	free(copy_swap_stack_a);
	swap_stack_a_third(stack_a, stack_b, num_in_a, num_in_b);
}
