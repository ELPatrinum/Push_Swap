/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:19:57 by muel-bak          #+#    #+#             */
/*   Updated: 2023/12/19 18:13:10 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*join_strings(char **array, int start_index)
{
    // Find the length of the array
    int len = 0;
    while (array[len] != NULL)
	{
        len++;
    }

    // Calculate the total length of the joined string
    int totalLength = 0;
    int i = start_index;
    while (i < len)
	{
        totalLength += ft_strlen(array[i]);
        i++;
    }

    // Add space for the separators (spaces) between elements
    totalLength += len - start_index - 1;

    // Allocate memory for the joined string
    char* result = (char*)malloc(totalLength + 1); // +1 for the null terminator
    if (result == NULL)
	{
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Copy elements into the result string
    i = start_index;
    int resultIndex = 0;
    while (i < len)
	{
        ft_strcpy(result + resultIndex, array[i]);
        resultIndex += ft_strlen(array[i]);
        if (i < len - 1) {
            // Add a space separator if not the last element
            result[resultIndex] = ' ';
            resultIndex++;
        }
        i++;
    }

    // Null-terminate the result string
    result[resultIndex] = '\0';

    return result;
}

char *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return s1;
}
char	**make_args(char **array)
{
	char	*pre_args;
	char	**args;
	
	pre_args = join_strings(array, 1);
	empty_string((const char *)pre_args);
	args = ft_split (pre_args, ' ');
	free(pre_args);
	return (args);
}
