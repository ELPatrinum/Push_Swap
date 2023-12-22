/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:23:43 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/22 03:35:30 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (is_empty(stack))
	{
		printf("Stack is empty\n");
		exit(EXIT_FAILURE);
	}
	printf("--------------- \n");
	printf("Stack elements: \n");
	current = stack->top;
	while (current != NULL)
	{
		printf(":%d: %d  :%d:\n", current->value, stack->len, current->indx);
		current = current->next;
	}
	printf("---------------\n");
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	av = is_valid(ac, av);
	if (!av)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	if (!initialize_stack(&stack_a, &stack_b, av))
	{
		write(2, "Error\n", 7);
		return (1);
	}
	if (!is_sorted_ascending(&stack_a))
	{
		set_indx(&stack_a);
		check_and_sort(&stack_a, &stack_b);
	}
	print_stack(&stack_a);
	free_stack(&stack_a);
}
