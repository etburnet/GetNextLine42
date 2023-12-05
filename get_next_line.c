/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:30:34 by eburnet           #+#    #+#             */
/*   Updated: 2023/12/05 15:23:25 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **previous_line)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*previous_line, buffer);
		free(*previous_line);
		*previous_line = temp;
		if (ft_strchr(buffer, '\n'))
			return (*previous_line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == 0 && (!*previous_line || (*previous_line)[0] == '\0'))
	{
		if (*previous_line)
			free(*previous_line);
		*previous_line = NULL;
		return (NULL);
	}
	return (*previous_line);
}

char	*extract_line(char **previous_line)
{
	char	*next_newline;
	char	*line;
	char	*temp;

	next_newline = ft_strchr(*previous_line, '\n');
	if (next_newline)
	{
		*next_newline = '\0';
		line = ft_strjoin(*previous_line, "\n");
		temp = ft_strdup(next_newline + 1);
		free(*previous_line);
		*previous_line = temp;
		return (line);
	}
	line = ft_strjoin(*previous_line, "\n");
	free(*previous_line);
	*previous_line = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*previous_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == -1)
		return (NULL);
	if (!previous_line)
		previous_line = ft_strdup("");
	previous_line = read_line(fd, &previous_line);
	if (!previous_line || previous_line[0] == '\0')
		return (NULL);
	line = extract_line(&previous_line);
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *result;
	while ((result = get_next_line(fd)) != NULL)
	{
		printf("%s", result);
		free(result);
	}
	close(fd);
	return (0);
} */