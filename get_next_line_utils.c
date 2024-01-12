/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:30:31 by eburnet           #+#    #+#             */
/*   Updated: 2024/01/12 11:04:01 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *previous_line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!previous_line)
	{
		previous_line = (char *)malloc(1 * sizeof(char));
		previous_line[0] = '\0';
	}
	if (!previous_line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(previous_line) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (previous_line)
		while (previous_line[++i] != '\0')
			str[i] = previous_line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(previous_line) + ft_strlen(buff)] = '\0';
	free(previous_line);
	return (str);
}
