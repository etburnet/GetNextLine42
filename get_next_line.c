/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:21:56 by eburnet           #+#    #+#             */
/*   Updated: 2024/01/18 15:01:09 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_make_line_remove(char *buff)
{
	int		i;
	int		j;
	char	*line;
	char	*rest;

	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	while (j <= i)
	{
		line[j] = buff[j];
		j++;
	}
	*line = '\0';
	rest = buff + i;
	while (*rest != '\0')
		*buff++ = *rest++;
	*buff = '\0';
	return (line);
}

char	*ft_read(int fd, char *buff)
{
	int		i;
	char	*temp;
	
	temp = malloc(sizeof (char *) * BUFFER_SIZE + 1);
	if (!temp)
		return NULL;
	while (ft_strchr(buff, '\n') == 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		buff = ft_strjoin(buff, temp);
		if (i < BUFFER_SIZE)
			ft_make_line_remove(buff);
		if (ft_strchr(buff, '\n') != 0)
			ft_make_line_remove(buff);
	}
	return NULL;
}

char	*get_next_line(int fd)
{
	static char	*buff;
	ft_read(fd, buff);
	ft_make_line_remove(buff);
	return ();
} 

#include <fcntl.h>
int	main()
{
	int	fd = open("42_with_nl", O_RDONLY);
	printf("%s", get_next_line(fd));
}
