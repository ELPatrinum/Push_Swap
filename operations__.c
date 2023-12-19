/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations__.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:39:48 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/19 15:19:14 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
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

void	initialize(t_stack *stack)
{
	stack->top = NULL;
}
