/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:09:11 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/21 14:32:02 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (stack->top->value < stack->top->next->value)
		return (1);
	else
		return (0);
}

int	is_sec_sorted(t_stack*stack)
{
	if (stack->top->next->value < stack->top->next->next->value)
		return (1);
	else
		return (0);
}

void	sort_three(t_stack *stack_a)
{
	if (!(is_sorted(stack_a)) && is_sec_sorted(stack_a))
	{
		if (stack_a->top->value > stack_a->top->next->next->value)
			ra(stack_a);
		else
			sa(stack_a);
	}
	else if ((is_sorted(stack_a)) && !is_sec_sorted(stack_a))
	{
		if (stack_a->top->value > stack_a->top->next->next->value)
		{
			ra(stack_a);
			ra(stack_a);
		}
		else 
		{
			sa(stack_a);
			ra(stack_a);
		}
	}
	else if (!(is_sorted(stack_a)) && !is_sec_sorted(stack_a))
	{
		ra(stack_a);
		sa(stack_a);
	}
}

void	check_and_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a) == 2)
	{
		(void)stack_b;
		if (!(is_sorted(stack_a)))
			sa(stack_a);
	}
	else if (stack_size(stack_a) == 3)
		sort_three(stack_a);
}
