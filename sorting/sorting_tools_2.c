/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:19:48 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/25 15:50:02 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

int	first_half_search(t_stack *stack, int *indx)
{
	int		i;
	t_node	*current;

	current = stack->top;
	i = 1;
	while (i <= (stack->len / 2) && current != NULL)
	{
		if (current->indx == *indx)
		{
			(*indx)++;
			return (i);
		}
		else
		{
			current = current->next;
			i++;
		}
	}
	return (0);
}

int	sec_half_search(t_stack *stack, int *indx)
{
	int		i;
	t_node	*current;

	current = stack->top;
	i = 1;
	while (i++ <= (stack->len / 2))
		current = current->next;
	while (current != NULL)
	{
		if (current->indx == *indx)
		{
			(*indx)++;
			return (i);
		}
		else
		{
			current = current->next;
			i++;
		}
	}
	return (0);
}

void	get_min_to_top(t_stack *stack_a, int *indx)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	i = first_half_search(stack_a, indx);
	if (i == 0)
		ii = sec_half_search(stack_a, indx);
	if (i > ii)
	{
		while (i > 1)
		{
			ra(stack_a);
			i--;
		}
	}
	if (ii > i)
	{
		ii -= 1;
		while (ii <= (stack_a->len))
		{
			rra(stack_a);
			ii++;
		}
	}
}

void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	indx;

	indx = 1;
	while (stack_size(stack_a) > 3)
	{
		get_min_to_top(stack_a, &indx);
		pb(stack_a, stack_b);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_size(stack_b) > 0)
	{
		pa(stack_a, stack_b);
	}
}
