/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:06:31 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/18 18:23:47 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

char	*read_from_fd(int fd, char *remains)
{
	char		*buff;
	long long	size;

	size = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(remains), NULL);
	while (size > 0 && !new_line_check(remains))
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == 0)
			break ;
		if (size == -1)
		{
			free(buff);
			free(remains);
			return (NULL);
		}
		buff[size] = '\0';
		remains = ft_strjoin(remains, buff);
	}
	free(buff);
	return (remains);
}

char	*get_theline(char *str)
{
	int		i;
	char	*line;

	if (!*str)
		return (NULL);
	line = malloc((ft_strlen_pro(str, 0, '\n') + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_remains(char *remains)
{
	char	*new_remains;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!remains)
		return (free(remains), NULL);
	while (remains[i] != '\0' && remains[i] != '\n')
		i++;
	if (!remains[i])
	{
		free(remains);
		return (NULL);
	}
	new_remains = malloc((ft_strlen_pro(remains, i, '\0')) * sizeof(char));
	if (!new_remains)
		return (free(remains), NULL);
	i++;
	while (remains[i])
		new_remains[j++] = remains[i++];
	new_remains[j] = '\0';
	free(remains);
	return (new_remains);
}

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*theline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remains = read_from_fd(fd, remains);
	if (!remains)
		return (NULL);
	theline = get_theline(remains);
	if (!theline)
	{
		free(remains);
		remains = NULL;
		return (NULL);
	}
	remains = update_remains(remains);
	return (theline);
}
