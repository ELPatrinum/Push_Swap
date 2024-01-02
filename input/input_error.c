/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:43:39 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/02 09:51:38 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

bool	is_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_all_digit(char *str, int sign)
{
	if (sign == 1)
	{
		str++;
		if (!*str)
			return (false);
	}
	while (*str)
	{
		if (!is_digit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	is_already_in(const t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		if (current->value == value)
			return (true);
		current = current->next;
	}
	return (false);
}
