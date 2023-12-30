/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:50:57 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/22 11:23:21 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

static bool is_valid_s(char *line)
{
  if (ft_strlen(line) == 3 && (line[1] == 'a' || line[1] == 'b' || line[1] == 's'))
    return(true);
  else 
    return (false);
}

static bool is_valid_p(char *line)
{
 if (ft_strlen(line) == 3 && (line[1] == 'a' || line[1] == 'b'))
    return(true);
  else 
    return (false);
}

static bool is_valid_r(char *line)
{
  if (ft_strlen(line) == 3 && (line[1] == 'a' || line[1] == 'b' || line[1] == 'r'))
    return(true);
  else 
    return (false);
}

static bool is_valid_rr(char *line)
{
  if (ft_strlen(line) == 4 && (line[2] == 'a' || line[2] == 'b' || line[1] == 'r'))
    return(true);
  else 
    return (false);
}

int excute_operation(t_stack *stack_a, t_stack *stack_b)
{
  char *line;

  line = get_next_line(0);
  while (line)
  {
    if (line[0] == 'p' && is_valid_p(line))
    {
      run_push(line, stack_a, stack_b);
    }
    else if (line[0] == 's' && is_valid_s(line))
    {
      run_swap(line, stack_a, stack_b);
    }
    else if (line[0] == 'r' && is_valid_r(line))
    {
      run_rotate(line, stack_a, stack_b);
    }
    else if (line[0] == 'r' && line[1] == 'r' && is_valid_rr(line))
    {
      run_reverse_rotate(line, stack_a, stack_b);
    }
    else 
      return(0);
    line = get_next_line(0);
  }
  return (1);
}

