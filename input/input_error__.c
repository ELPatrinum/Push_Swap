/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error__.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:22:28 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/21 23:23:42 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

void	empty_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 1)
		exit(EXIT_FAILURE);
	while (av[i])
	{
		empty_string(av[i]);
		if (!*av[1])
		{
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		i++;
	}
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
