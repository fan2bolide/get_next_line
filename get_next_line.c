/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:32:06 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/16 15:14:49 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add_buffer(char *buf, char *line, int *size)
{
	int	i;

	i = 0;
	while (buf[i] > 0 && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = ft_strfusion(buf, size, line, i);
	ft_memmove((char *)buf, buf + i + 1, BUFFER_SIZE - i + 1);
	return (line);
}

char	*ft_read_buffer(int fd, char *buf, char *line, int size)
{
	int	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read == BUFFER_SIZE && !ft_isset('\n', buf))
	{
		line = ft_add_buffer(buf, line, &size);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (!ft_isset('\n', buf))
		buf[BUFFER_SIZE] = EOF;
	line = ft_add_buffer(buf, line, &size);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1] = {0};
	char			*line;
	int				size;

	if (ft_isset(EOF, buffer))
		return (NULL);
	line = malloc(sizeof(char) * 1);
	*line = 0;
	size = 1;
	if (buffer[BUFFER_SIZE] == EOF)
	{
		free(line);
		return (NULL);
	}
	if (buffer[0])
	{
		line = ft_add_buffer((char *)buffer, line, &size);
		if (ft_isset('\n', line) || ft_isset(EOF, line))
			return (line);
	}
	return (ft_read_buffer(fd, (char *)buffer, line, size));
}
