/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:09:37 by totoletoto        #+#    #+#             */
/*   Updated: 2025/03/07 00:47:19 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*concat_args(int argc, char **argv)
{
	char		*result;
	int			total_length;
	int			i;
	int			pos;

	i = 1;
	pos = 0;
	total_length = measure_length(argc, argv);
	result = malloc(sizeof(char) * (total_length + 1));
	if (!result)
		return (NULL);
	while (i < argc)
	{
		pos += ft_strlcpy(result + pos, argv[i], total_length - pos + 1);
		if (i < argc - 1)
		{
			result[pos] = ' ';
			pos++;
		}
		i++;
	}
	result[total_length] = '\0';
	return (result);
}

int	measure_length(int argc, char **argv)
{
	int	total_length;
	int	i;

	total_length = 0;
	i = 1;
	while (i < argc)
	{
		total_length += ft_strlen(argv[i]);
		if (i < argc - 1)
			total_length++;
		i++;
	}
	return (total_length);
}

int	find_min(int *stack, int size)
{
	int	min;
	int	i;

	i = 0;
	min = stack[i];
	while (i < size)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	find_max(int *stack, int size)
{
	int	max;
	int	i;

	i = 0;
	max = stack[i];
	while (i < size)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

char	*merge_str(int argc, char **argv)
{
	char	*str;

	if (argc > 2)
		str = concat_args(argc, argv);
	else
		str = argv[1];
	return (str);
}
