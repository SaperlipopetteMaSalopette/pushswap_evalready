/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:23:55 by totoletoto        #+#    #+#             */
/*   Updated: 2025/03/07 00:35:55 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libraries/libft/libft.h"

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	max_size;
}	t_stacks;

int		check_args(int argc, char **argv, t_stacks *stacks);

long	ft_safe_atol(const char *str);

void	free_stacks(t_stacks *stacks);

void	free_shelf(char **numbers);

void	print_stacks(t_stacks *stacks);

void	radix_sort(t_stacks *stacks);

int		sort_all(t_stacks *stacks);

int		contains_space(char **strs, int count);

int		is_valid_number(char *str);

int		numbers_count(char *str);

int		check_dupli(char **number_list);

int		find_min(int *stack, int size);

int		find_max(int *stack, int size);

int		measure_length(int argc, char **argv);

char	*concat_args(int argc, char **argv);

int		already_sorted(char **number_list);

int		proceed_checks(int argc, char **argv);

int		is_only_spaces(char *str);

int		empty_or_not(char **numbers);

int		ft_isspace(char c);

int		is_number(char **numbers);

int		is_legal_int(char **numbers);

int		init_stacks(int argc, char **argv, t_stacks *stacks);

char	*merge_str(int argc, char **argv);

int		check_error(char **number_list);

void	index_stack(t_stacks *stacks);

void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

int		solve_two(t_stacks *stacks);
int		solve_three(t_stacks *stacks);
void	solve_four(t_stacks *stacks);
void	solve_five(t_stacks *stacks);

#endif
