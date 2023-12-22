/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 01:28:53 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/22 03:43:44 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

char	**is_valid(int ac, char **av)
{
	if (empty_args(ac, av))
		return (NULL);
	av = make_args(av);
	return (av);
}

bool	fits_in_int(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (false);
	else
		return (true);
}

bool	empty_args(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac == 1)
		return (true);
	while (av[++i])
	{
		if (!*av[i] || is_spaces(av[i]))
			return (true);
	}
	return (false);
}

int	len_without_zero(char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[j])
		j++;
	len = j - i;
	return (len);
}
