/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:33:00 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/12 22:07:10 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];
	int			size;
	static		pos;

	size = 1;
	buf[BUFFER_SIZE] = 0;
	line = calloc(sizeof(char), size);
	line[0] = 0;
	while (read(fd, buf, BUFFER_SIZE) && ft_isset('\n', buf))
	{
		line = ft_realloc(line, size + BUFFER_SIZE);
		ft_strncat(line, buf, BUFFER_SIZE);
	}
	line[size] = 0;
	return (line);
}
