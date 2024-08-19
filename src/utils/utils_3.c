/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:21:51 by astefans          #+#    #+#             */
/*   Updated: 2024/07/05 18:14:37 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi_long(const char *str)
{
	char			*nbr;
	long long		i;
	long long		sign;
	long long		res;

	res = 0;
	sign = 1;
	i = 0;
	nbr = (char *)str;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9' )
	{
		res = res * 10 + nbr[i] - '0';
		i++;
	}
	return (sign * res);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

int	numbers_input(long *stack_a, int *num_in_a,
	char **argv, char **numbers_list)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	numbers_list = ft_split(argv[1], 32);
	while (numbers_list[i])
	{
		num++;
		i++;
	}
	num_in_a[0] = num;
	num_in_a[1] = num_in_a[0];
	i = 0;
	while (i < num_in_a[0])
	{
		stack_a[i] = ft_atoi_long(numbers_list[i]);
		i++;
	}
	free_str(numbers_list);
	free(numbers_list);
	return (0);
}

int	check_separated_input(long *stack_a, int *num_in_a, char **argv)
{
	int	i;

	i = 0;
	while (i < num_in_a[1])
	{
		if (only_numbers(argv[i + 1]) == 1)
			stack_a[i] = ft_atoi_long(argv[i + 1]);
		else
		{
			write(1, "ERROR\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	separating_input(long *stack_a, int *num_in_a, char **argv)
{
	char	**numbers_list;

	numbers_list = NULL;
	if (num_in_a[0] == 1)
	{
		if (numbers_input(stack_a, num_in_a, argv, numbers_list))
			return (-1);
	}
	else
	{
		if (check_separated_input(stack_a, num_in_a, argv) == -1)
			return (-1);
	}
	if (duplicates(stack_a, num_in_a[1]) == -1)
		return (-1);
	if (number_limit(stack_a, num_in_a[1]) == -1)
		return (-1);
	return (0);
}
