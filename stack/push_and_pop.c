/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:24:26 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/19 16:04:39 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_node	*new_node)
{
	new_node->next = stack->top;
	new_node->prev = NULL;
	if (!is_empty(stack))
		stack->top->prev = new_node;
	stack->top = new_node;
}

t_node	*pop(t_stack *stack)
{
	t_node	*popped;

	if (is_empty(stack))
	{
		write(2, ":POP: nothing to pop, stack is empty\n", 38);
		exit(EXIT_FAILURE);
	}
	popped = stack->top;
	stack->top = stack->top->next;
	if (!is_empty(stack))
		stack->top->prev = NULL;
	return (popped);
}
