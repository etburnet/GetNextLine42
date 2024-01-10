/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:30:34 by eburnet           #+#    #+#             */
/*   Updated: 2024/01/10 21:51:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **previous_line)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*previous_line, buffer);
		free(*previous_line);
		*previous_line = temp;
		if (ft_strchr(buffer, '\n'))
		{
			free(buffer);
			return (*previous_line);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
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
	line = ft_strjoin(*previous_line, "");
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
	int fd = open("gnlTester/files/43_with_nl", O_RDONLY);
	char *result;
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
} */