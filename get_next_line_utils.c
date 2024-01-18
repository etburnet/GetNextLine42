/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:07:59 by eburnet           #+#    #+#             */
/*   Updated: 2024/01/18 09:57:08 by eburnet          ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	int		i;
	char	*result;

	if (!s1)
		return (NULL);
	i = 0;
	lens1 = ft_strlen(s1);
	result = malloc(sizeof(char) * (lens1 + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (*s1 != '\0')
		result[i++] = *(s1++);
	i = 0;
	while (*s2 != '\0')
		result[lens1 + i++] = *(s2++);
	result[lens1 + i] = '\0';
	return (result);
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
