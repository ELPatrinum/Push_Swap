/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:34:35 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/25 13:40:18 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*popped;

	if (!is_empty(stack_b))
	{
		popped = pop(stack_b);
		push(stack_a, popped);
	}
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*popped;

	if (!is_empty(stack_a))
	{
		popped = pop(stack_a);
		push(stack_b, popped);
	}
}
