/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:28:41 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/19 15:19:27 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct t_node
{
	struct t_node	*prev;
	int				value;
	struct t_node	*next;	
}	t_node;

typedef struct t_stack
{
	t_node	*top;
}	t_stack;

char	**ft_split(char const *s, char c);
long	ft_atoi(char *str);
void	handle_input_error(int ac, char **av);
char	**free_(char **arr);
int		spaces(char *str);
int		ft_strlen(char *str);
void	empty_string(const char *s);
char	*ft_strdup(const char *str);
t_node	*creat_node(int value);
int		is_empty(t_stack *stack);
void	push(t_stack *stack, t_node	*new_node);
t_node	*pop(t_stack *stack);
void	free_stack(t_stack *stack);
void	init_stack(char **av, t_stack *stack_a);
int		stack_size(t_stack *stack);
int		stack_size(t_stack *stack);
void	initialize(t_stack *stack);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
int		is_empty(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif