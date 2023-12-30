/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:28:41 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/30 18:37:47 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct t_node
{
	struct t_node	*prev;
	int				value;
	int				indx;
	struct t_node	*next;	
}	t_node;

typedef struct t_stack
{
	t_node	*top;
	int		len;
}	t_stack;

typedef struct t_indx
{
	int	l1;
	int	l2;
	int	l3;
}	t_indx;

//// ---------pars----------
bool	is_spaces(char *str);
bool	empty_args(int ac, char **av);
bool	is_digit(char c);
bool	is_all_digit(char *str, int sign);
bool	fits_in_int(long nbr);
char	**is_valid(int ac, char **av);
char	**ft_split(char const *s, char c);
long	ft_atoi(char *str);
char	**free_(char **arr);
int		ft_strlen(char *str);
int		len_without_zero(char *str);
char	*ft_strdup(const char *str);
char	**make_args(char **array);
char	*ft_strcpy(char *s1, char *s2);
void	copy_elements(int start_index, char **array, char *result, int len);
//// ---------stack----------
bool	is_empty(t_stack *stack);
bool	initialize_stack(t_stack *stack_a, t_stack *stack_b, char **av);
int		stack_size(t_stack *stack);
void	free_stack(t_stack *stack);
void	initialize(t_stack *stack);
void	push(t_stack *stack, t_node	*new_node);
t_node	*pop(t_stack *stack);
t_node	*creat_node(int value);
void	set_indx(t_stack *stack);
//// ---------tools----------
bool	is_already_in(const t_stack *stack, int value);
bool	init_stack(char **av, t_stack *stack_a);
bool		is_sorted(t_stack *stack);
void	check_and_sort(t_stack *stack_a, t_stack *stack_b);
long	get_min(t_stack *stack);
int		indexed_stack_size(t_stack *stack);
//// ---------sort_tools----------
void	exec_top(t_stack *stack_a, t_stack *stack_b, int * check, int max);
void	exec_bot(t_stack *stack_a, t_stack *stack_b , int *check , int max);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);
int		max_search(t_stack *stack, int indx);
int		get_tail(t_stack *stack);
int		search_max(t_stack *stack_a);
//// ---------sorting----------
void	big_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	sort_4(t_stack *stack_a, t_stack *stack_b);
void	sort_5(t_stack *stack_a, t_stack *stack_b);
//// ---------operations----------
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif
