/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indixing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 23:29:11 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/27 09:56:32 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

long	get_min(t_stack *stack)
{
	long	min;
	t_node	*current;

	current = stack->top;
	min = 2147483648;
	while (current)
	{
		if (current->value < min && !current->indx)
			min = current->value;
		current = current->next;
	}
	return (min);
}

void	set_indx(t_stack *stack)
{
	t_node	*current;
	int		i;
	long	min;

	current = stack->top;
	i = 1;
	if (stack)
	{
		while (current)
		{
			min = get_min(stack);
			if (min == 2147483648)
				return;
			else if (current->value == min)
			{
				current->indx = i++;
				current = stack->top;
			}
			else
				current = current->next;
		}
	}
	return;
}
