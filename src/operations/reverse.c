/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:54:17 by astefans          #+#    #+#             */
/*   Updated: 2024/07/08 16:15:38 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot_stack_a(long *stack_a, int *num_in_a)
{
	int		i;
	long	*temp;

	i = num_in_a[1] - 1;
	temp = (long *)malloc(sizeof(long));
	*temp = stack_a[num_in_a[1] - 1];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = *temp;
	free(temp);
	write(1, "rra\n", 4);
}

void	rev_rot_stack_b(long *stack_b, int *num_in_b)
{
	int		i;
	long	*temp;

	i = *num_in_b - 1;
	temp = (long *)malloc(sizeof(long));
	*temp = stack_b[*num_in_b - 1];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = *temp;
	free(temp);
	write(1, "rrb\n", 4);
}

void	rev_a_and_b(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b)
{
	int		i;
	long	*temp;

	i = num_in_b[1] - 1;
	temp = (long *)malloc(sizeof(long));
	*temp = stack_a[num_in_a[1] - 1];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = *temp;
	i = 0;
	*temp = stack_b[0];
	while (i < *num_in_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[*num_in_b - 1] = *temp;
	free(temp);
	write(1, "rrr\n", 4);
}
