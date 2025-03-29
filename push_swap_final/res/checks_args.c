/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:49:04 by thofstet          #+#    #+#             */
/*   Updated: 2025/03/07 00:46:24 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	free_shelf(char **numbers)
{
	int	i;

	i = -1;
	if (!numbers)
		return ;
	while (numbers[++i])
		free(numbers[i]);
	free(numbers);
}

int	is_legal_int(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (ft_strlen(numbers[i]) > 11 || ft_atol(numbers[i]) > 2147483647
			|| ft_atol(numbers[i]) <= -2147483648)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_number(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}
