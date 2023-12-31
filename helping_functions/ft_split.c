/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:09:17 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/27 11:24:58 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

static size_t	count_strings(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*split_it(size_t *i, char const *s, char c)
{
	size_t	index;
	size_t	size;
	size_t	tmp;
	char	*res;

	while (s[*i] && s[*i] == c)
		(*i)++;
	tmp = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	size = *i - tmp;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	index = 0;
	while (tmp + index < *i)
	{
		res[index] = s[tmp + index];
		index++;
	}
	res[index] = '\0';
	return (res);
}

char	**free_(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;

	ptr = malloc((ft_strlen((char *)str) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < (size_t)ft_strlen((char *)str))
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	strings_number;
	size_t	i;
	char	**result;

	if (!s)
		return (NULL);
	i = 0;
	index = 1;
	strings_number = count_strings(s, c);
	result = (char **)malloc(sizeof(char *) * (strings_number + 2));
	if (!result)
		return (NULL);
	result[0] = ft_strdup("push_swap");
	while (index <= strings_number)
	{
		result[index] = split_it(&i, s, c);
		if (!result[index])
			return (free_(result));
		index++;
	}
	result[strings_number + 1] = NULL;
	return (result);
}
