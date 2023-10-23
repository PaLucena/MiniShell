/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxuxer <lxuxer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:25:34 by rdelicad          #+#    #+#             */
/*   Updated: 2023/07/22 11:02:30 by lxuxer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *buffer)
{
	int		bytes_read;
	char	readed[BUFFER_SIZE + 1];

	ftg_bzero(readed, BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0 && !ftg_strchr(readed))
	{
		bytes_read = read(fd, readed, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		if (bytes_read == 0 && buffer == NULL)
			return (NULL);
		readed[bytes_read] = '\0';
		buffer = ftg_strjoin(buffer, readed);
		if (!buffer)
			return (free(buffer), buffer = NULL, NULL);
	}
	return (buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		line_lengt;
	int		i;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	line_lengt = 0;
	while (buffer[line_lengt] != '\0' && buffer[line_lengt] != '\n')
		line_lengt++;
	line = ftg_calloc(line_lengt + 1 + (buffer[line_lengt] == '\n'), 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[line_lengt] == '\n')
		line[line_lengt++] = '\n';
	line[line_lengt] = '\0';
	return (line);
}

char	*clear_buffer(char *buffer)
{
	char	*copy;
	int		line_lengt;
	int		i;

	line_lengt = 0;
	while (buffer[line_lengt] != '\0' && buffer[line_lengt] != '\n')
		line_lengt++;
	if (buffer[line_lengt] == '\0')
	{
		free (buffer);
		return (buffer = NULL, NULL);
	}
	copy = ftg_calloc((ftg_strlen(buffer) - line_lengt + 1), sizeof(char));
	if (copy == NULL)
		return (free(buffer), free(copy), copy = NULL, buffer = NULL, NULL);
	i = 0;
	line_lengt++;
	while (buffer[line_lengt + i])
	{
		copy[i] = buffer[line_lengt + i];
		i++;
	}
	copy[i] = '\0';
	free(buffer);
	return (buffer = NULL, copy);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (buffer != 0)
		{
			free(buffer);
			buffer = 0;
		}
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (free(buffer), buffer = NULL, NULL);
	line = extract_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = clear_buffer(buffer);
	if (buffer == NULL)
		return (free(buffer), buffer = NULL, line);
	return (line);
}
