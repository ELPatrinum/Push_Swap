/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:24:26 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/19 16:04:39 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push(t_stack *stack, t_node	*new_node)
{
	new_node->next = stack->top;
	new_node->prev = NULL;
	if (!is_empty(stack))
		stack->top->prev = new_node;
	stack->top = new_node;
}

t_node	*pop(t_stack *stack)
{
	t_node	*popped;

	if (is_empty(stack))
	{
		write(2, ":POP: nothing to pop, stack is empty\n", 38);
		exit(EXIT_FAILURE);
	}
	popped = stack->top;
	stack->top = stack->top->next;
	if (!is_empty(stack))
		stack->top->prev = NULL;
	return (popped);
}

void	free_stack(t_stack *stack)
{
	while (!is_empty(stack))
	{
		pop(stack);
	}
}

void	init_stack(char **av, t_stack *stack_a)
{
	int	i;

	i = 0;
	if (!av)
	{
		write(2, ":INIT_STACK: argument vector is NULL!!\n", 40);
		exit(EXIT_FAILURE);
	}
	while (av[i + 1] != NULL)
		i++;
	while (i >= 1)
	{
		push(stack_a, creat_node(ft_atoi(av[i])));
		i--;
	}
}
