/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:21:51 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/01/06 16:25:41 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*join_line(char *s1, char *s2)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!line)
		return (NULL);
	while (s1 && s1[i])
	{
		line[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] && s2[j - 1] != '\n')
	{
		line[i + j] = s2[j];
		j++;
	}
	line[i + j] = '\0';
	return (line);
}
