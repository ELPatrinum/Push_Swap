/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:43:39 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/19 15:58:57 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_input_error(int ac, char **av)
{
	char	**values;
	long	tmp;
	int		i;

	if (ac == 2)
	{
		values = ft_split(av[1], ' ');
		i = 1;
		while (values[i])
		{
			tmp = ft_atoi(values[i++]);
		}
	}
	if (ac > 2)
	{
		i = 1;
		while (av[i])
			tmp = ft_atoi(av[i++]);
	}
}

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
	if (!str)
	{
		write(2, ":strlen: NULL pointer!\n", 24);
		exit(EXIT_FAILURE);
	}
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	empty_string(const char *s)
{
	if (ft_strlen((char *)s) == spaces((char *)s))
	{
		write(2, "Push-SWAP:ERROR: Argument is an empty string!\n", 47);
		exit(1);
	}
}
