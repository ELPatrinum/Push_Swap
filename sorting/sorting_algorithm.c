/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:30:52 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/21 16:31:23 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

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
			rra(stack_a);
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