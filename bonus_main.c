/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:23:43 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/30 01:14:45 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/push_swap.h"

int	main(int ac, char **av)
{
  int     check;
	t_stack	stack_a;
	t_stack	stack_b;

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
	check = excute_operation(&stack_a, &stack_b);
  if (!check)
    write(1, "Error\n", 7);
  else if (check && !is_sorted(&stack_a))
      write(1, "KO\n", 3);
  else if (check && is_sorted(&stack_a))
    write(1, "OK\n", 3);
	free_stack(&stack_a);
	free_(av);
}
