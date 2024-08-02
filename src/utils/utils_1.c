/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:40:01 by astefans          #+#    #+#             */
/*   Updated: 2024/07/08 13:06:14 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b)
{
	free(stack_a);
	free(stack_b);
	free(num_in_a);
	free(num_in_b);
	exit(0);
}

int	stack_size(int argc, char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ')
				size++;
			i++;
		}
	}
	else
		size = argc - 1;
	return (size);
}

int	duplicates(long *stack_a, int num_in_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < num_in_a)
	{
		j = 0;
		while (j < num_in_a)
		{
			if ((stack_a[i] == stack_a[j]) && (i != j))
			{
				write(1, "ERROR\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_new_allocation(long **tab, int startsize, int newsize)
{
	int		i;
	long	*temp;

	i = 0;
	if (tab != NULL && *tab != NULL && startsize < newsize)
	{
		temp = malloc(sizeof(long) * newsize);
		while (i < startsize)
		{
			temp[i] = (*tab)[i];
			i++;
		}
		*tab = temp;
	}
	else if ((*tab != NULL) && (startsize > newsize))
	{
		temp = malloc(sizeof(long) * (newsize));
		while (i < newsize)
		{
			temp[i] = (*tab)[i];
			i++;
		}
		*tab = temp;
	}
}

void	operations(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b)
{
	push_stack_a(stack_a, stack_b, num_in_a, num_in_b);
	rotate_stack_a(stack_a, num_in_a);
}
