/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:09:11 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/31 03:01:58 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

void	ft_sa(t_stack *stack_a)
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

void	ft_sb(t_stack *stack_b)
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

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
