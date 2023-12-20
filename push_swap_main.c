/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:23:43 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/19 18:21:32 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack) {
    if (is_empty(stack))
	{
        printf("Stack is empty\n");
        return;
    }

    printf("--------------- \n");
    printf("Stack elements: \n");
    t_node *current = stack->top;
    while (current != NULL) {
        printf(":%d:\n", current->value);
        current = current->next;
    }
	 printf("---------------\n");
}


int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac == 1)
		return (1);
	if (!*av[1])
		return (write(2, "Error\n", 7), 2);
	av = make_args(av);
	initialize(&stack_a);
  initialize(&stack_b);
	init_stack(av, &stack_a);
	print_stack(&stack_a);
  //av = free_(av);
}
