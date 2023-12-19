/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:24:26 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/19 12:28:56 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*creat_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		write(2, ":Push: node allocation failed\n", 31);
		exit(EXIT_FAILURE);
	}
	new_node->value = value;
	return (new_node);
}

int	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

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

void	free_stack(t_stack *stack)
{
	while (!is_empty(stack))
	{
		pop(stack);
	}
}
