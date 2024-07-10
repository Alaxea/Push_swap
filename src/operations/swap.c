/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:54:42 by astefans          #+#    #+#             */
/*   Updated: 2024/07/08 16:17:21 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_a(long *stack_a, int *num_in_a)
{
	long	*temp;

	temp = (long *)malloc(sizeof(long));
	if (num_in_a[1] > 1)
	{
		temp[0] = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp[0];
	}
	free(temp);
	write(1, "sa\n", 3);
}

void	swap_stack_b(long *stack_b, int *num_in_b)
{
	long	*temp;

	temp = (long *)malloc(sizeof(long));
	if (*num_in_b > 1)
	{
		temp[0] = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp[0];
	}
	free(temp);
	write(1, "sb\n", 3);
}

void	swap_stack_a_and_b(long *stack_a, long *stack_b,
	int *num_in_a, int *num_in_b)
{
	long	*temp;

	temp = (long *)malloc(sizeof(long));
	if (num_in_a[1] > 1)
	{
		temp[0] = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp[0];
	}
	if (*num_in_b > 1)
	{
		temp[0] = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp[0];
	}
	free(temp);
	write(1, "ss\n", 3);
}
