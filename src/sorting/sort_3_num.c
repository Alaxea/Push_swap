/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:37:56 by astefans          #+#    #+#             */
/*   Updated: 2024/06/27 16:26:01 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_num(long *stack_a, int *num_in_a)
{
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] < stack_a[2])
		&& (stack_a[0] < stack_a[2]))
		swap_stack_a(stack_a, num_in_a);
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] > stack_a[2])
		&& (stack_a[0] > stack_a[2]))
	{
		swap_stack_a(stack_a, num_in_a);
		rev_rot_stack_a(stack_a, num_in_a);
	}
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] < stack_a[2])
		&& (stack_a[0] > stack_a[2]))
		rotate_stack_a(stack_a, num_in_a);
	if ((stack_a[0] < stack_a[1]) && (stack_a[1] > stack_a[2])
		&& (stack_a[0] < stack_a[2]))
	{
		swap_stack_a(stack_a, num_in_a);
		rotate_stack_a(stack_a, num_in_a);
	}
	if ((stack_a[0] < stack_a[1]) && (stack_a[1] > stack_a[2])
		&& (stack_a[0] > stack_a[2]))
		rev_rot_stack_a(stack_a, num_in_a);
}
