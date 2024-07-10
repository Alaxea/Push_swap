/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:54:07 by astefans          #+#    #+#             */
/*   Updated: 2024/06/25 11:45:29 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack_a(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b)
{
	int	i;

	(num_in_a[1])++;
	i = num_in_a[1] - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < *num_in_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	(*num_in_b)--;
	if (*num_in_b == 0)
		stack_b = NULL;
	write(1, "pa\n", 3);
}

void	push_stack_b(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b)
{
	int	i;

	(*num_in_b)++;
	i = *num_in_b - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < num_in_a[1])
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	(num_in_a[1])--;
	if (num_in_a[1] == 0)
		stack_a = NULL;
	write(1, "pb\n", 3);
}
