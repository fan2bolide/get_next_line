/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:38:45 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/12 22:07:59 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strncat(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n < 0)
		return (s1);
	while (s1[i])
		i++;
	while (s2[i] && j < n)
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

	if (str == NULL)
		return (NULL);
	newstr = malloc(sizeof(char) * size);
	if (newstr == NULL)
		return (NULL);
	ft_strncpy(newstr, str, size);
	free(str);
	return (newstr);
}
