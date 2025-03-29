/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:47:30 by thofstet          #+#    #+#             */
/*   Updated: 2025/03/29 15:50:10 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solve_two(t_stacks *stacks)
{
	if (stacks->size_a != 2)
		return (0);
	if (stacks->stack_a[0] > stacks->stack_a[1])
		sa(stacks);
	return (1);
}

int	solve_three(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_a[0];
	b = stacks->stack_a[1];
	c = stacks->stack_a[2];
	if (a > b && b < c && a < c)
		sa(stacks);
	else if (a > b && b > c)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (a > b && b < c && a > c)
		ra(stacks);
	else if (a < b && b > c && a < c)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (a < b && b > c && a > c)
		rra(stacks);
	return (1);
}

void	solve_four(t_stacks *stacks)
{
	int	min;
	int	i;

	i = 0;
	min = find_min(stacks->stack_a, stacks->size_a);
	while (stacks->stack_a[0] != min)
	{
		if (i > stacks->size_a / 2)
			rra(stacks);
		else
			ra(stacks);
		i++;
	}
	pb(stacks);
	solve_three(stacks);
	pa(stacks);
}

void	solve_five(t_stacks *stacks)
{
	int	min;
	int	index;
	int	rotations;

	min = find_min(stacks->stack_a, stacks->size_a);
	index = 0;
	while (index < stacks->size_a && stacks->stack_a[index] != min)
		index++;
	if (index <= stacks->size_a / 2)
	{
		rotations = index;
		while (rotations--)
			ra(stacks);
	}
	else
	{
		rotations = stacks->size_a - index;
		while (rotations--)
			rra(stacks);
	}
	pb(stacks);
	solve_four(stacks);
	pa(stacks);
}
