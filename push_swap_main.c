/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:23:43 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/19 15:44:50 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to print all elements of the stack
void print_stack(t_stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: \n");
    t_node *current = stack->top;
    while (current != NULL) {
        printf(":%d:\n", current->value);
        current = current->next;
    }
    printf("\n");
}


int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac == 1)
		return (1);
	if (!*av[1])
		return (write(2, "Push-SWAP:ERROR: Empty arguments!!\n", 33), 2);
	handle_input_error(ac, av);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	initialize(&stack_a);
    initialize(&stack_b);
	init_stack(av, &stack_a);
	print_stack(&stack_a);
}
