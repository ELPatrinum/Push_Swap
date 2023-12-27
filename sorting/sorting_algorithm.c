/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:30:52 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/27 10:15:58 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_indx i;

	(1 == 1) && (i.l1 =  stack_a->len / 3, i.l2 =  stack_a->len / 6 , i.l3 = 0);
	while (stack_a->len != 3)
	{
		if (stack_a->top->indx < i.l1)
		{
			if (stack_a->top->indx < i.l2)
				pb(stack_a, stack_b);
			else
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
		}
		else 
			ra(stack_a);
		if (i.l1  - 1 == stack_b->len)
		{
			i.l3 = i.l1;
			i.l1 += stack_a->len / 3;
			i.l2 = i.l3 + stack_a->len / 6;
		}
	}
}

