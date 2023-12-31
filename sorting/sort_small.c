/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 02:43:34 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/31 02:39:00 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

static int	get_min1(t_stack *stack, int val)
{
	t_node	*head;
	int		min;

	head = stack->top;
	min = head->indx;
	while (head->next)
	{
		head = head->next;
		if ((head->indx < min) && head->indx != val)
			min = head->indx;
	}
	return (min);
}

static int	get_distance(t_stack *stack, int index)
{
	t_node	*head;
	int		distance;

	distance = 0;
	head = stack->top;
	while (head)
	{
		if (head->indx == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min1(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min1(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
