/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:01:03 by astefans          #+#    #+#             */
/*   Updated: 2024/07/08 13:10:01 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_digit(int i)
{
	while (i >= '0' && i <= '9')
		return (1);
	return (0);
}

int	only_numbers(char *num)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while (num[i])
	{
		if (num[i] == 45)
		{
			if (i != 0)
				return (0);
			minus++;
		}
		else if (is_digit(num[i]) == 0)
			return (0);
		i++;
	}
	if (minus > 1)
		return (0);
	return (1);
}

int	number_limit(long *stack_a, int *num_in_a)
{
	int	i;

	i = 0;
	while (i < *num_in_a)
	{
		if ((stack_a[i] > 2147483648) || (stack_a[i] < -2147483648))
		{
			write(1, "ERROR\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	is_stack_is_sorted(long *stack_a, int *num_in_a)
{
	int		i;
	int		j;
	long	max;

	i = 1;
	j = 0;
	max = stack_a[0];
	while (i < num_in_a[1])
	{
		if (stack_a[i] > max)
		{
			max = stack_a[i];
			j++;
		}
		i++;
	}
	if (j == num_in_a[1] - 1)
		return (0);
	return (-1);
}
