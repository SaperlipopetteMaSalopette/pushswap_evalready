/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:20:00 by totoletoto        #+#    #+#             */
/*   Updated: 2025/03/07 00:37:04 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks		stacks;

	if (argc < 2)
		return (0);
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.size_a = 0;
	stacks.size_b = 0;
	if (!proceed_checks(argc, argv))
		return (0);
	if (!init_stacks(argc, argv, &stacks))
		return (0);
	sort_all(&stacks);
	free_stacks(&stacks);
	return (0);
}

int	init_stacks(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	int		num_count;
	char	*str;
	char	**numbers;

	str = merge_str(argc, argv);
	numbers = ft_split(str, ' ');
	num_count = numbers_count(str);
	if (argc > 2)
		free(str);
	stacks->stack_a = malloc(sizeof(int) * num_count);
	stacks->stack_b = malloc(sizeof(int) * num_count);
	if (!stacks->stack_a || !stacks->stack_b)
	{
		free_stacks(stacks);
		return (0);
	}
	i = -1;
	while (++i < num_count)
		stacks->stack_a[i] = ft_atol(numbers[i]);
	free_shelf(numbers);
	stacks->size_a = num_count;
	stacks->size_b = 0;
	stacks->max_size = num_count;
	return (1);
}

int	numbers_count(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
		{
			count++;
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
	return (count);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->stack_a)
		free(stacks->stack_a);
	if (stacks->stack_b)
		free(stacks->stack_b);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
}

int	ft_isspace(char c)
{
	if ((c == 32) || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
