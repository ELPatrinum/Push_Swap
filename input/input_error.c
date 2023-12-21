/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:43:39 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/21 21:53:10 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

int	spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
		{
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (i);
}

void	empty_string(const char *s)
{
	if (ft_strlen((char *)s) == spaces((char *)s))
	{
		write(2, "Error\n", 7);
		exit(1);
	}
}

void	max_int_(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
}

void	is_already_in(const t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		if (current->value == value)
		{
			write(2, "Error\n", 7);
			exit(1);
		}
		current = current->next;
	}
}
