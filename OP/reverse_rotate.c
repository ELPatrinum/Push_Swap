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

void	rra(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (stack_a->top && stack_a->top->next)
	{
		first = stack_a->top;
		last = stack_a->top;
		while (last->next)
		{
			last = last->next;
		}
		last->prev->next = NULL;
		first->prev = last;
		last->next = first;
		last->prev = NULL;
		stack_a->top = last;
	}
}

void	rrb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (stack_b->top && stack_b->top->next)
	{
		first = stack_b->top;
		last = stack_b->top;
		while (last->next)
		{
			last = last->next;
		}
		last->prev->next = NULL;
		first->prev = last;
		last->next = first;
		last->prev = NULL;
		stack_b->top = last;
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
