/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:08:15 by totoletoto        #+#    #+#             */
/*   Updated: 2025/02/13 06:13:01 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	temp = stacks->stack_a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
	temp = stacks->stack_b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
	ft_putendl_fd("rrr", 1);
}
