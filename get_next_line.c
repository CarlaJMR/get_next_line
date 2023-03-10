/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:23:58 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/01/10 14:53:09 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	reset_buffer(char *buffer)
{
	int			i;
	int			flag;

	flag = -1;
	i = 0;
	while (buffer[i] && flag == -1)
	{
		if (buffer[i] == '\n')
			flag = i + 1;
		i++;
	}
	i = 0;
	if (flag != -1)
	{
		while (buffer[flag + i])
		{
			buffer[i] = buffer[flag + i];
			i++;
		}
		while (buffer[i])
			buffer[i++] = 0;
	}
	else
		while (buffer[i])
			buffer[i++] = 0;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (read(fd, buffer, 0) < 0)
	{
		buffer[0] = 0;
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE))
	{
		line = join_line(line, buffer);
		reset_buffer(buffer);
		if (line[ft_strlen(line) - 1] == '\n')
			break ;
	}
	return (line);
}
