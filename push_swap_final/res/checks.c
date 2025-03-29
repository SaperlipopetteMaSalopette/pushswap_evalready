/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:11:22 by thofstet          #+#    #+#             */
/*   Updated: 2025/02/16 14:09:25 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	empty_or_not(char **numbers)
{
	if (!numbers || !numbers[0])
		return (1);
	if (ft_strlen(numbers[0]) == 0)
		return (1);
	if (is_only_spaces(numbers[0]))
		return (1);
	return (0);
}

int	already_sorted(char **number_list)
{
	int		i;
	long	prev;
	long	current;

	i = 1;
	prev = ft_atol(number_list[0]);
	while (number_list[i])
	{
		current = ft_atol(number_list[i]);
		if (current < prev)
			return (0);
		prev = current;
		i++;
	}
	return (1);
}

int	check_dupli(char **number_list)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 0;
	while (number_list[i])
	{
		num_i = atol(number_list[i]);
		j = i + 1;
		while (number_list[j])
		{
			num_j = atol(number_list[j]);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(char **number_list)
{
	if (empty_or_not(number_list))
		return (2);
	if (!is_number(number_list))
		return (1);
	if (!is_legal_int(number_list))
		return (1);
	if (check_dupli(number_list))
		return (1);
	if (already_sorted(number_list))
		return (2);
	return (0);
}

int	proceed_checks(int argc, char **argv)
{
	int			input_value;
	char		**number_list;
	char		*concatenated_args;

	if (argc == 2)
		number_list = ft_split(argv[1], ' ');
	else
	{
		concatenated_args = concat_args(argc, argv);
		number_list = ft_split(concatenated_args, ' ');
		free(concatenated_args);
	}
	input_value = check_error(number_list);
	free_shelf(number_list);
	if (input_value == 1)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (input_value == 2)
		return (0);
	return (1);
}
