/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:19:57 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/30 18:37:13 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

static char	*join_strings(char **array, int start_index)
{
	int		len;
	int		totallength;
	int		i;
	char	*result;

	len = 0;
	while (array[len] != NULL)
		len++;
	totallength = 0;
	i = start_index;
	while (i < len)
	{
		totallength += ft_strlen(array[i]);
		i++;
	}
	totallength += len - start_index - 1;
	result = (char *)malloc(totallength + 1);
	if (result == NULL)
	{
		write(2, "Memory allocation error\n", 25);
		exit(EXIT_FAILURE);
	}
	copy_elements(start_index, array, result, len);
	return (result);
}

void	copy_elements(int start_index, char **array, char *result, int len)
{
	int	i;
	int	resultindex;

	i = start_index;
	resultindex = 0;
	while (i < len)
	{
		ft_strcpy(result + resultindex, array[i]);
		resultindex += ft_strlen(array[i]);
		if (i < len - 1)
		{
			result[resultindex] = ' ';
			resultindex++;
		}
		i++;
	}
	result[resultindex] = '\0';
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

char	**make_args(char **array)
{
	char	*pre_args;
	char	**args;

	pre_args = join_strings(array, 1);
	if (pre_args[0] == '\0')
		return (NULL);
	if (is_spaces(pre_args))
		return (free(pre_args), NULL);
	args = ft_split (pre_args, ' ');
	free(pre_args);
	return (args);
}
