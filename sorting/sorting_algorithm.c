/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:30:52 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/30 18:28:42 by muel-bak         ###   ########.fr       */
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

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		pos_max;
	int		max;

	int check = 0; 
	max = get_tail(stack_a);//tail fixe 
	while (stack_b->len)
	{
		pos_max = max_search(stack_b, stack_a->top->indx - 1);
		if (pos_max == 2)
			exec_top(stack_a, stack_b, &check, max);
		else if (pos_max == 1)
			exec_bot(stack_a, stack_b, &check, max);
		while (get_tail(stack_a) == stack_a->top->indx - 1)
			rra(stack_a);
	}
}
