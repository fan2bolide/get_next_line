/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:38:45 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/18 03:08:04 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	if (source > dest)
	{
		while (i < (int)len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			dest[i] = source[i];
			i--;
		}
	}
	return (dest);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j] && j < n)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = 0;
	return (s1);
}

char	*ft_realloc(char *str, int size)
{
	char	*newstr;
	size_t	len_str;

	if (str == NULL)
		return (NULL);
	newstr = malloc(sizeof(char) * size);
	if (newstr == NULL)
		return (NULL);
	len_str = 0;
	while (str[len_str])
		len_str++;
	ft_memmove(newstr, str, len_str + 1);
	free(str);
	return (newstr);
}

char	*ft_strfusion(char const *buf, int *size, char *line, int buf_size)
{
	if (buf_size == 0)
		return (line);
	*size += buf_size;
	line = ft_realloc(line, *size);
	line = ft_strncat(line, buf, buf_size);
	return (line);
}
