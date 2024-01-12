/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:06:05 by eburnet           #+#    #+#             */
/*   Updated: 2024/01/12 10:58:51 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_find(int fd, char *previous_line)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(previous_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		previous_line = ft_strjoin(previous_line, buff);
	}
	free(buff);
	return (previous_line);
}

char	*extract_line(char *previous_line)
{
	int		i;
	char	*str;

	i = 0;
	if (previous_line[i] == 0)
		return (NULL);
	while (previous_line[i] != 0 && previous_line[i] != '\n')
		i++;
	str = malloc(sizeof(char *) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (previous_line[i] != 0 && previous_line[i] != '\n')
	{
		str[i] = previous_line[i];
		i++;
	}
	if (previous_line[i] == '\n')
	{
		str[i] = previous_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*update_line(char *previous_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (previous_line[i] != 0 && previous_line[i] != '\n')
		i++;
	if (previous_line[i] == 0)
	{
		free(previous_line);
		return (NULL);
	}
	str = malloc(sizeof(char *) * (ft_strlen(previous_line) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	while (previous_line[i] != 0)
		str[j++] = previous_line[i++];
	str[j] = '\0';
	free(previous_line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*previous_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	previous_line = read_and_find(fd, previous_line);
	if (previous_line == NULL)
		return (NULL);
	line = extract_line(previous_line);
	previous_line = update_line(previous_line);
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char *tamere;

	int fd = open("bible.txt", O_RDONLY);
	tamere = get_next_line(fd);
	while (tamere != NULL)
	{
		printf("%s",tamere);
		tamere = get_next_line(fd);
	}
	close(fd);
	return (0);
} */