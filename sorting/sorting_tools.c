/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:09:11 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/31 02:58:53 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

void	check_and_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 2)
	{
		if (!(is_sorted(stack_a)))
			sa(stack_a);
	}
	else if (stack_a->len == 3)
		sort_three(stack_a);
	else if (stack_a->len == 4)
		sort_4(stack_a, stack_b);
	else if (stack_a->len == 5)
		sort_5(stack_a, stack_b);
	else
	{
		push_to_b(stack_a, stack_b);
		if (!(is_sorted(stack_a)))
			sort_three(stack_a);
		big_sort(stack_a, stack_b);
	}
}

void	sort_three(t_stack *stack_a)
{
	int	max;

	max = search_max(stack_a);
	if (stack_a->top->indx == max)
		ra(stack_a);
	else if (stack_a->top->next->indx == max)
		rra(stack_a);
	if (stack_a->top->indx > stack_a->top->next->indx)
		sa(stack_a);
}

bool	is_sorted(t_stack *stack)
{
	t_node	*current;
	t_node	*prev;

	current = stack->top;
	prev = NULL;
	while (current)
	{
		if (prev != NULL && current->value < prev->value)
			return (false);
		prev = current;
		current = current->next;
	}
	return (true);
}

int	search_max(t_stack *stack_a)
{
	t_node	*tmp;
	int		max;

	tmp = stack_a->top;
	max = tmp->indx;
	while (tmp)
	{
		if (max < tmp->indx)
			max = tmp->indx;
		tmp = tmp->next;
	}
	return (max);
}
