/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:23:43 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/02 09:52:00 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (!av[1])
		return (0);
	av = is_valid(ac, av);
	if (!av)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	if (!initialize_stack(&stack_a, &stack_b, av))
	{
		write(2, "Error\n", 7);
		free_stack(&stack_a);
		return (free_(av), 1);
	}
	if (!is_sorted(&stack_a))
	{
		set_indx(&stack_a);
		check_and_sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_(av);
}
