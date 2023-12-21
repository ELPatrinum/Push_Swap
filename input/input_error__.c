/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error__.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:22:28 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/21 12:24:22 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

void	empty_args(int ac, char **av)
{
	if (ac == 1)
		exit(EXIT_FAILURE);
	if (!*av[1])
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
}
