/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:33:00 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/14 19:39:22 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*ft_strfusion(char const *buf, int *size, char *line, int buf_size)
{
	*size += buf_size;
	line = ft_realloc(line, *size);
	line = ft_strncat(line, buf, buf_size);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];
	int			size;
	static int	pos = 0;
	static int	old_fd = 0;

	size = 1;
	if (fd != old_fd)
		pos = 0;
	buf[BUFFER_SIZE] = 0;
	line = calloc(sizeof(char), size);
	line[0] = 0;
	if (pos == BUFFER_SIZE)
		pos = 0;
	if (pos != 0)
		line = ft_strfusion(buf + pos, &size, line, BUFFER_SIZE - pos);
	while (read(fd, buf, BUFFER_SIZE) > 0 && !ft_isset('\n', buf))
		line = ft_strfusion(buf, &size, line, BUFFER_SIZE);
	while (pos < BUFFER_SIZE && buf[pos] != '\n')
		pos++;
	if (pos && pos != BUFFER_SIZE)
		line = ft_strfusion(buf, &size, line, pos++);
	return (line);
}
