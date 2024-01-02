/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:09:11 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/02 10:27:21 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/push_swap.h"

int	main(int ac, char **av)
{
	int		check;
	t_stack	stack_a;
	t_stack	stack_b;

	if (!av[1])
		return (0);
	av = is_valid(ac, av);
	check = 1;
	if (!av)
		return (write(2, "Error\n", 7), 1);
	if (!initialize_stack(&stack_a, &stack_b, av))
	{
		write(2, "Error\n", 7);
		free_stack(&stack_a);
		return (free_(av), 1);
	}
	check = excute_operation(&stack_a, &stack_b);
	if (!check)
		write(1, "Error\n", 7);
	else if (check && !is_sorted(&stack_a))
		write(1, "KO\n", 3);
	else if (is_sorted(&stack_a))
		write(1, "OK\n", 3);
	return (free_stack(&stack_a), free_(av), 0);
}
