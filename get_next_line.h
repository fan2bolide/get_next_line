/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:39:11 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/13 04:35:52 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strncpy(char *src, char *dest, int n);
char	*ft_strfusion(char const *buf, int *size, char *line, int buf_size);
char	*ft_realloc(char *str, int size);
char	*ft_strncat(char *s1, const char *s2, unsigned int n);
int		ft_isset(char c, char const *set);
char	*get_next_line(int fd);