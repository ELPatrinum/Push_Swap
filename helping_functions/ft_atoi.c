/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:50:57 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/21 11:34:38 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

static long	calc_result(long tmp, long result, char c, int sign)
{
	tmp = (result * 10) + (c - 48);
	if (tmp < result && sign == 1)
		return (-1);
	else if (tmp < result && sign == -1)
		return (0);
	return (tmp);
}

long	_error(char *str, int j)
{
	int	i;

	i = j;
	if (str[i] < '0' || str[i] > '9')
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;
	long	tmp;

	i = 0;
	sign = 1;
	result = 0;
	tmp = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	_error(str, i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = calc_result(tmp, result, str[i], sign);
		i++;
	}
	return (sign * result);
}
