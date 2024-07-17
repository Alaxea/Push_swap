/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:17:35 by astefans          #+#    #+#             */
/*   Updated: 2024/07/08 12:59:07 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(int *num_in_a, int *num_in_b)
{
	free(num_in_a);
	free(num_in_b);
	exit(0);
}

void	free_and_exit_with_error(int *num_in_a, int *num_in_b)
{
	free(num_in_a);
	free(num_in_b);
	write(1, "ERROR\n", 6);
	exit(0);
}

void	check_parameters(int argc, char **argv, int *num_in_a, int *num_in_b)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		free_and_exit(num_in_a, num_in_b);
	while (i < argc)
	{
		if ((argv[i][ft_strlen(argv[i]) - 1] == ' ') || (argv[i][0] == ' '))
			free_and_exit_with_error(num_in_a, num_in_b);
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (((argv[i][j] < 48) || (argv[i][j] > 57)) && (argv[i][j] != 32))
			{
				if (argv[i][j] != 45)
					free_and_exit_with_error(num_in_a, num_in_b);
			}
			if ((argv[i][j] == 32) && (argv[i][j + 1] == 32))
				free_and_exit_with_error(num_in_a, num_in_b);
			j++;
		}
		i++;
	}
}

void	set_numbers(int *num_in_a, int *num_in_b, int argc)
{
	num_in_a[0] = argc - 1;
	num_in_a[1] = num_in_a[0];
	*num_in_b = 0;
}

int	main(int argc, char **argv)
{
	long	*stack_a;
	long	*stack_b;
	int		*num_in_a;
	int		*num_in_b;

	num_in_a = (int *)malloc(2 * sizeof(int));
	num_in_b = (int *)malloc(sizeof(int));
	check_parameters(argc, argv, num_in_a, num_in_b);
	set_numbers(num_in_a, num_in_b, argc);
	stack_a = (long *)malloc(sizeof(long) * stack_size(argc, argv));
	stack_b = (long *)malloc(sizeof(long) * stack_size(argc, argv));
	if ((separating_input(stack_a, num_in_a, argv) == -1)
		|| (is_stack_is_sorted(stack_a, num_in_a) == 0))
	{
		free_stacks(stack_a, stack_b, num_in_a, num_in_b);
		return (1);
	}
	if ((num_in_a[1] == 2) && (stack_a[0] > stack_a[1]))
		rotate_stack_a(stack_a, num_in_a);
	else if (num_in_a[1] == 3)
		sort_3_num(stack_a, num_in_a);
	else if (num_in_a[1] == 5)
		sort_5_num(stack_a, stack_b, num_in_a, num_in_b);
	else
		sort_other(stack_a, stack_b, num_in_a, num_in_b);
	free_stacks(stack_a, stack_b, num_in_a, num_in_b);
	return (0);
}
