/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:36:29 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/21 14:23:01 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	free_stack(t_stack *stack)
{
	while (!is_empty(stack))
	{
		free(pop(stack));
	}
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = stack->top;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	initialize_stack(t_stack *stack_a, t_stack *stack_b, char **av)
{
	initialize(stack_a);
	initialize(stack_b);
	init_stack(av, stack_a);
}
