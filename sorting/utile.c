#include "../header_file/push_swap.h"

int get_tail(t_stack *stack)
{
	t_node *current;

	current = stack->top;
	if(!stack)
		return (0);
	while (current->next)
		current = current->next;
	return(current->indx);	
}

int	 max_search(t_stack *stack, int indx)
{
	t_node	*current;

	int len = stack->len / 2;
	current = stack->top;
	if (stack)
	{
		while (current)
		{
			if (current->indx == indx)
			{
				if (len > 0)
					return (2);
				return (1);	
			}
			current = current->next;
			len--;
		}
	}	
		return (0);
}
void	exec_top(t_stack *stack_a, t_stack *stack_b, int * check, int max)
{
	while (stack_b->top->indx != stack_a->top->indx - 1 )
	{
		// printf("stack_b->top->indx :%d: stack_a->top->indx -1 :%d:\n",stack_b->top->indx, stack_a->top->indx - 1 );
		// print_stack(stack_a);
		// printf("get_tail %d\n", get_tail(stack_a));
		// sleep(4);
		if (!*check || stack_b->top->indx > get_tail(stack_a))
		{
			pa(stack_a,stack_b);
			ra(stack_a);
			(*check) = 1;	
		}
		else
			rb(stack_b);
		if (max == get_tail(stack_a))
			(*check) = 0;
	}
	pa(stack_a, stack_b);
}

void	exec_bot(t_stack *stack_a, t_stack *stack_b , int *check , int max)
{
	while (stack_b->top->indx != stack_a->top->indx - 1)
	{
		if (!*check || stack_b->top->indx > get_tail(stack_a))
		{
			pa(stack_a,stack_b);
			ra(stack_a);
			(*check) = 1;
		}
		else
			rrb(stack_b);
		if (max == get_tail(stack_a))
			(*check) = 0;
	}
	pa(stack_a, stack_b);
}
