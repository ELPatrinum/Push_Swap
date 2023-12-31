/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:09:11 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/31 03:06:21 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

int	get_tail(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	if (!stack)
		return (0);
	while (current->next)
		current = current->next;
	return (current->indx);
}

int	max_search(t_stack *stack, int indx)
{
	t_node	*current;
	int		len;

	current = stack->top;
	len = stack->len / 2;
	if (stack)
	{
		while (current)
		{
			if (current->indx == indx)
			{
				if (len > 0)
					return (2);
				return (1);
			}
			current = current->next;
			len--;
		}
	}
	return (0);
}

void	exec_top(t_stack *stack_a, t_stack *stack_b, int *check, int max)
{
	while (stack_b->top->indx != stack_a->top->indx - 1)
	{
		if (!*check || stack_b->top->indx > get_tail(stack_a))
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			(*check) = 1;
		}
		else
			rb(stack_b);
		if (max == get_tail(stack_a))
			(*check) = 0;
	}
	pa(stack_a, stack_b);
}

void	exec_bot(t_stack *stack_a, t_stack *stack_b, int *check, int max)
{
	while (stack_b->top->indx != stack_a->top->indx - 1)
	{
		if (!*check || stack_b->top->indx > get_tail(stack_a))
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			(*check) = 1;
		}
		else
			rrb(stack_b);
		if (max == get_tail(stack_a))
			(*check) = 0;
	}
	pa(stack_a, stack_b);
}
