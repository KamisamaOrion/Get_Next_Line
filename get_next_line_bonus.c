/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:01:34 by mhervoch          #+#    #+#             */
/*   Updated: 2023/11/22 19:57:41 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_the_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 1 + (buffer[i] == '\n'), sizeof(char));
	while (j <= i && line)
	{
		line[j] = buffer[j];
		j++;
	}
	free(buffer);
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	str = ft_calloc((ft_strlen(s1, '\0') + \
				ft_strlen (s2, '\0') + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}

char	*ft_extraction(char *line)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
		return (NULL);
	i++;
	if (!line[i])
		return (NULL);
	k = i;
	while (line[i++])
		j++;
	str = ft_calloc(j + 1, sizeof(char));
	j = 0;
	while (line[k])
	{
		str[j] = line[k++];
		j++;
	}
	return (str);
}

char	*read_line(char	*line, int fd, char **str, int *i)
{
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (freeall(str[fd], line, buffer));
	*i = read(fd, buffer, BUFFER_SIZE);
	if (*i < 0)
		return (freeall(line, str[fd], buffer));
	if (*i == 0)
		free(buffer);
	else
	{
		line = ft_strjoin(line, buffer);
		free(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[1024] = {NULL};
	char		*line;
	int			i;

	i = 1;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = ft_strjoin(str[fd], line);
	while (ft_no_n(line) && i > 0)
		line = read_line(line, fd, str, &i);
	if (!line)
		return (NULL);
	str[fd] = ft_extraction(line);
	line = get_the_line(line);
	return (line);
}
