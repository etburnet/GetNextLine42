/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:30:31 by eburnet           #+#    #+#             */
/*   Updated: 2023/11/22 13:11:17 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == (char)character)
			return ((char *)str);
		str++;
	}
	if (*str == (char)character)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	result = NULL;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		slen;
	char	*str;
	char	*cpy;

	str = (char *)s;
	slen = ft_strlen(s);
	cpy = (char *)malloc(slen + 1);
	i = 0;
	if (cpy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
