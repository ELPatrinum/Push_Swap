/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:24:26 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/27 08:37:44 by muel-bak         ###   ########.fr       */
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
	new_node->indx = 0;
	return (new_node);
}

void	initialize(t_stack *stack)
{
	stack->top = NULL;
	stack->tail = NULL;
	stack->len = 0;
}

bool	init_stack(char **av, t_stack *stack_a)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	while (av[i + 1] != NULL)
		i++;
	while (i >= 1)
	{
		sign = 0;
		if (av[i][0] == '-' || av[i][0] == '+')
			sign++;
		if (!is_all_digit(av[i], sign))
			return (false);
		if (len_without_zero(av[i]) > 11)
			return (false);
		nbr = ft_atoi(av[i]);
		if (!fits_in_int(nbr))
			return (false);
		if (is_already_in(stack_a, nbr))
			return (false);
		push(stack_a, creat_node(nbr));
		i--;
	}
	return (true);
}
