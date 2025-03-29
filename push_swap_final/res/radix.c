/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:46:42 by thofstet          #+#    #+#             */
/*   Updated: 2025/02/13 07:32:31 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stacks *stacks)
{
	int	*temp;
	int	i;
	int	j;
	int	pos;

	temp = malloc(sizeof(int) * stacks->size_a);
	i = -1;
	while (++i < stacks->size_a)
	{
		j = -1;
		pos = 0;
		while (++j < stacks->size_a)
			if (stacks->stack_a[i] > stacks->stack_a[j])
				pos++;
		temp[i] = pos;
	}
	i = -1;
	while (++i < stacks->size_a)
		stacks->stack_a[i] = temp[i];
	free(temp);
}

void	radix_sort(t_stacks *stacks)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	index_stack(stacks);
	size = stacks->size_a;
	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((stacks->stack_a[0] >> i) & 1)
				ra(stacks);
			else
				pb(stacks);
		}
		while (stacks->size_b)
			pa(stacks);
	}
}

int	sort_all(t_stacks *stacks)
{
	if (stacks->size_a == 2)
		solve_two(stacks);
	if (stacks->size_a == 3)
		solve_three(stacks);
	if (stacks->size_a == 4)
		solve_four(stacks);
	if (stacks->size_a == 5)
		solve_five(stacks);
	if (stacks->size_a > 5)
		radix_sort(stacks);
	return (1);
}
