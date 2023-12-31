/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:28:41 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/31 02:57:58 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

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
bool	is_sorted(t_stack *stack);
void	check_and_sort(t_stack *stack_a, t_stack *stack_b);
long	get_min(t_stack *stack);
int		indexed_stack_size(t_stack *stack);
//// ---------sort_tools----------
void	exec_top(t_stack *stack_a, t_stack *stack_b, int *check, int max);
void	exec_bot(t_stack *stack_a, t_stack *stack_b, int *check, int max);
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
//// ---------get_next_line----------
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*get_remains(char *remains);
char	*get_theline(char *str);
char	*read_from_fd(int fd, char *res);
int		ft_strlen_pro(char *s, int j, char c);
int		new_line_check(char *str);
char	*ft_strjoin(char *s1, char *s2);
///// ----------------bonus----------------
void	run_push(char *line, t_stack *stack_a, t_stack *stack_b);
void	run_swap(char *line, t_stack *stack_a, t_stack *stack_b);
void	run_rotate(char *line, t_stack *stack_a, t_stack *stack_b);
void	run_reverse_rotate(char *line, t_stack *stack_a, t_stack *stack_b);
int		excute_operation(t_stack *stack_a, t_stack *stack_b);
//// -----------bonus_op-----------
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_ra(t_stack *stack_a);
void	ft_rb(t_stack *stack_b);
void	ft_rra(t_stack *stack_a);
void	ft_rrb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

#endif
