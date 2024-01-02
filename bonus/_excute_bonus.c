/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:09:11 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/31 03:01:04 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

void	run_push(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (line[1] == 'a')
		ft_pa(stack_a, stack_b);
	else
		ft_pb(stack_a, stack_b);
}

void	run_swap(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (line[1] == 'a')
		ft_sa(stack_a);
	else if (line[1] == 'b')
		ft_sb(stack_b);
	else
		ft_ss(stack_a, stack_b);
}

void	run_rotate(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (line[1] == 'a')
		ft_ra(stack_a);
	else if (line[1] == 'b')
		ft_rb(stack_b);
	else
		ft_rr(stack_a, stack_b);
}

void	run_reverse_rotate(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (line[2] == 'a')
		ft_rra(stack_a);
	else if (line[2] == 'b')
		ft_rrb(stack_b);
	else
		ft_rrr(stack_a, stack_b);
}
