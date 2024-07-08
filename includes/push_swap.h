/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:03:58 by astefans          #+#    #+#             */
/*   Updated: 2024/07/08 13:54:50 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

void	push_stack_a(long *stack_a, long *stack_b,
			int *num_in_a, int *num_in_b);
void	push_stack_b(long *stack_a, long *stack_b,
			int *num_in_a, int *num_in_b);
void	rev_rot_stack_a(long *stack_a, int *num_in_a);
void	rev_rot_stack_b(long *stack_b, int *num_in_b);
void	rev_a_and_b(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b);
void	rotate_stack_a(long *stack_a, int *num_in_a);
void	rotate_stack_b(long *stack_b, int *num_in_b);
void	rot_a_and_b(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b);
void	swap_stack_a(long *stack_a, int *num_in_a);
void	swap_stack_b(long *stack_b, int *num_in_b);
void	swap_stack_a_and_b(long *stack_a, long *stack_b,
			int *num_in_a, int *num_in_b);
void	sort_3_num(long *stack_a, int *num_in_a);
void	sort_5_num(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b);
void	sort_other(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b);
void	free_stacks(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b);
void	parameters(long *stack_a, long *stack_b, int *num_in_a, int *num_in_b);
void	ft_new_allocation(long **tab, int startsize, int newsize);
void	free_str(char **str);
int		stack_size(int argc, char **argv);
int		duplicates(long *stack_a, int *num_in_a);
int		ft_strlen(const char *str);
int		is_digit(int i);
int		only_numbers(char *num);
int		number_limit(long *stack_a, int *num_in_a);
int		is_stack_is_sorted(long *stack_a, int *num_in_a);
int		ft_atoi(const char *str);
int		numbers_input(long *stack_a, int *num_in_a,
			char **argv, char **numbers_list);
int		check_separated_input(long *stack_a, int *num_in_a, char **argv);
int		separating_input(long *stack_a, int *num_in_a, char **argv);
char	**ft_split(const char *str, char c);

#endif
