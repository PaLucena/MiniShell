/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:25:34 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:04:10 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*read_file(int fd, char *buffer)
{
	int		bytes_read;
	char	readed[BUFFER_SIZE + 1];

	ft_bzero(readed, BUFFER_SIZE + 1);
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
		buffer = ft_strjoin(buffer, readed);
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
	line = ft_calloc(line_lengt + 1 + (buffer[line_lengt] == '\n'), 1);
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
	copy = ft_calloc((ft_strlen(buffer) - line_lengt + 1), sizeof(char));
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

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (buffer[fd] != 0)
		{
			free(buffer[fd]);
			buffer[fd] = 0;
		}
		return (NULL);
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	line = extract_line(buffer[fd]);
	if (line == NULL)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = clear_buffer(buffer[fd]);
	if (buffer[fd] == NULL)
		return (free(buffer[fd]), buffer[fd] = NULL, line);
	return (line);
}
