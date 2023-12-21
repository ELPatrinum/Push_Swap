/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:28:41 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/21 12:36:59 by muel-bak         ###   ########.fr       */
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
char	**free_(char **arr);
int		spaces(char *str);
int		ft_strlen(char *str);
void	empty_string(const char *s);
void	empty_args(int ac, char **av);
void	max_int_(long nbr);
void	is_already_in(const t_stack *stack, int value);
int		is_sorted(t_stack *stack);
char	*ft_strdup(const char *str);
char	*join_strings(char **array, int start_index);
char	**make_args(char **array);
char	*ft_strcpy(char *s1, char *s2);
t_node	*creat_node(int value);
int		is_empty(t_stack *stack);
void	push(t_stack *stack, t_node	*new_node);
t_node	*pop(t_stack *stack);
void	free_stack(t_stack *stack);
void	init_stack(char **av, t_stack *stack_a);
int		stack_size(t_stack *stack);
int		stack_size(t_stack *stack);
void	initialize(t_stack *stack);
void	initialize_stack(t_stack *stack_a, t_stack *stack_b, char **av);
void	copy_elements(int start_index, char **array, char *result, int len);

void	check_and_sort(t_stack *stack_a, t_stack *stack_b);

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
