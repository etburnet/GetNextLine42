/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:21:56 by eburnet           #+#    #+#             */
/*   Updated: 2024/01/18 12:04:05 by eburnet          ###   ########.fr       */
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

void	ft_read(int fd, char *buff)
{
	int		i;
	char	*temp;
	
	temp = malloc(sizeof (char *) * BUFFER_SIZE + 1);
	if (!temp)
		return ;
	while (ft_strchr(buff, '\n') == 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		buff = ft_strjoin(buff, temp);
		if (i < BUFFER_SIZE)
			ft_make_line_remove(buff);
		if (ft_strchr(buff, '\n') != 0)
			ft_make_line_remove(buff);
	}
	return ;
}

char	*get_next_line(int fd)
{
	static char 	*buff;
	ft_read(fd, buff);
}

#include <fcntl.h>
void	main()
{
	int	fd = open("42_with_nl", O_RDONLY);
	printf("%s", get_next_line(fd));
}















/* 	

	int		j;

	
	while (ft_backspace(buff, '\n') != NULL)
	{
		i = read(fd, temp, BUFFER_SIZE);
		buff = ft_strjoin(buff, temp);
	}
	return(buff); */