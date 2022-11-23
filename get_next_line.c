/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:32:06 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/23 17:58:10 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_add_buffer(char *buf, char *line, int *size)
{
	int	i;

	i = 0;
	while (buf[i] > 0 && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = ft_strfusion(buf, size, line, i);
	ft_memmove((char *)buf, buf + i, BUFFER_SIZE - i + 1);
	i = BUFFER_SIZE - i;
	while (i++ < BUFFER_SIZE)
		buf[i] = 0;
	return (line);
}

static char	*ft_read_buffer(int fd, char *buf, char *line, int size)
{
	int	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 1)
	{
		buf[BUFFER_SIZE] = EOF;
		if (*line)
			return (line);
		free(line);
		return (NULL);
	}
	while (bytes_read == BUFFER_SIZE && !ft_isset('\n', buf))
	{
		line = ft_add_buffer(buf, line, &size);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	line = ft_add_buffer(buf, line, &size);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1] = {0};
	char			*line;
	int				size;
	static int		old_fd = -1;

	if (fd >= OPEN_MAX || fd < 0 || read(fd, NULL, 0) != 0)
		return (buffer[0] = 0, NULL);
	if (old_fd != fd && old_fd != -1)
		buffer[0] = 0;
	old_fd = fd;
	if (ft_isset(EOF, buffer))
		return (NULL);
	line = malloc(sizeof(char) * 1);
	*line = 0;
	size = 1;
	if (buffer[BUFFER_SIZE] == EOF)
		return (free(line), NULL);
	if (buffer[0])
	{
		line = ft_add_buffer((char *)buffer, line, &size);
		if (ft_isset('\n', line) || ft_isset(EOF, line))
			return (line);
	}
	return (ft_read_buffer(fd, (char *)buffer, line, size));
}
