/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:31:27 by astefans          #+#    #+#             */
/*   Updated: 2024/06/28 13:33:56 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_rotation_a(long *stack_a, int *num_in_a)
{
	rotate_stack_a(stack_a, num_in_a);
	rotate_stack_a(stack_a, num_in_a);
}

void	two_rev_rotation_a(long *stack_a, int *num_in_a)
{
	rev_rot_stack_a(stack_a, num_in_a);
	rev_rot_stack_a(stack_a, num_in_a);
}
	
void	stack_one(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b)
{
	if (stack_b[0] < stack_a[0])
		push_stack_a(stack_a, stack_b, num_in_a, num_in_b);
	else if ((stack_b[0] > stack_a[0]) && (stack_b[0] < stack_a[1]))
	{
		rotate_stack_a(stack_a, num_in_a);
		push_stack_a(stack_a, stack_b, num_in_a, num_in_b);
		rev_rot_stack_a(stack_a, num_in_a);
	}
	else if ((stack_b[0] > stack_a[1]) && (stack_b[0] < stack_a[2]))
	{
		rev_rot_stack_a(stack_a, num_in_a);
		push_stack_a(stack_a, stack_b, num_in_a, num_in_b);
		rev_rot_stack_a(stack_a, num_in_a);
		rev_rot_stack_a(stack_a, num_in_a);	
	}
	else if (stack_b[0] > stack_a[2])
	{
		push_stack_a(stack_a, stack_b, num_in_a, num_in_b);
		rotate_stack_a(stack_a, num_in_a);
	}	
}

void	stack_two(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b)
{
	if (stack_b[0] < stack_a[0])
		push_stack_a(stack_a, stack_b, num_in_a, num_in_b);
	else if ((stack_b[0] > stack_a[0]) && (stack_b[0] < stack_a[1]))
	{
		rotate_stack_a(stack_a, num_in_a);
		push_stack_a(stack_a, stack_b, num_in_a, num_in_b);
		rev_rot_stack_a(stack_a, num_in_a);
	}
	else if ((stack_b[0] > stack_a[1]) && (stack_b[0] < stack_a[2]))
	{
		rotate_stack_a(stack_a, num_in_a);
		push_stack_a(stack_a, stack_b, num_in_a, num_in_b);
		swap_stack_a(stack_a, num_in_a);
		rev_rot_stack_a(stack_a, num_in_a);
	}
	else if ((stack_b[0] > stack_a[2]) && (stack_b[0] < stack_a[3]))
	{
		rev_rot_stack_a(stack_a, num_in_a);
		push_stack_a(stack_a, stack_b, num_in_a, num_in_b);
		two_rotation_a(stack_a, num_in_a);
	}
	else if (stack_b[0] > stack_a[3])
		operations(stack_a, stack_b, num_in_a, num_in_b);
}

void	sort_5_num(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b)
{
	push_stack_b(stack_a, stack_b, num_in_a, num_in_b);
	push_stack_b(stack_a, stack_b, num_in_a, num_in_b);
	sort_3_num(stack_a, num_in_a);
	while (*num_in_b != 0)
	{
		if (num_in_a[1] == 3)
			stack_one(stack_a, stack_b, num_in_a, num_in_b);
		else if (num_in_a[1] == 4)
			stack_two(stack_a, stack_b, num_in_a, num_in_b);
	}
}
