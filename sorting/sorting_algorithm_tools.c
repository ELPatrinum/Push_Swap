/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_tools.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:16:10 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/27 08:54:48 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"



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
