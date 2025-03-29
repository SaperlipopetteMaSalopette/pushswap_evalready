/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:31:35 by thofstet          #+#    #+#             */
/*   Updated: 2024/12/18 03:17:34 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list_libft **stack, t_list_libft *new)
{
	new->next = *stack;
	*stack = new;
}

// Adds the specified node to a stack (list) making it the head
