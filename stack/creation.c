/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:24:26 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/21 11:58:49 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

t_node	*creat_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		write(2, ":Push: node allocation failed\n", 31);
		exit(EXIT_FAILURE);
	}
	new_node->value = value;
	return (new_node);
}

void	initialize(t_stack *stack)
{
	stack->top = NULL;
}

void	init_stack(char **av, t_stack *stack_a)
{
	int		i;
	long	nbr;

	i = 0;
	if (!av)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	while (av[i + 1] != NULL)
		i++;
	while (i >= 1)
	{
		nbr = ft_atoi(av[i]);
		max_int_(nbr);
		is_already_in(stack_a, nbr);
		push(stack_a, creat_node(nbr));
		i--;
	}
}
