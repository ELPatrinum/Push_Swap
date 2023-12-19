/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:34:35 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/19 13:22:02 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (stack_a->top && stack_a->top->next)
	{
		first = stack_a->top;
		second = stack_a->top->next;
		first->next = second->next;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
		stack_a->top = second;
	}
}

void	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (stack_b->top && stack_b->top->next)
	{
		first = stack_b->top;
		second = stack_b->top->next;
		first->next = second->next;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
		stack_b->top = second;
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*popped;

	if (!is_empty(stack_b))
	{
		popped = pop(stack_b);
		push(stack_a, popped);
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*popped;

	if (!is_empty(stack_a))
	{
		popped = pop(stack_a);
		push(stack_b, popped);
	}
}

int	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}
