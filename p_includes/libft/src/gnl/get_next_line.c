/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:15:07 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/13 16:42:22 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_concat_free(char *str_ac, char *temp)
{
	char	*joined_str;

	joined_str = ft_strjoin_mod(str_ac, temp);
	free(str_ac);
	return (joined_str);
}

char	*ft_find_char(int fd, char *str_ac)
{
	char	*temp;
	int		read_return;

	if (!str_ac)
		str_ac = ft_calloc(1, sizeof(char));
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_return = 1;
	while (read_return > 0)
	{
		read_return = read(fd, temp, BUFFER_SIZE);
		if (read_return < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[read_return] = '\0';
		str_ac = ft_concat_free(str_ac, temp);
		if (ft_strchr_mod(temp, '\n') == 1)
			break ;
	}
	free(temp);
	return (str_ac);
}

char	*ft_get_line(char *str_ac)
{
	char	*line;
	size_t	i;
	size_t	len;

	i = 0;
	if (str_ac[i] == '\0')
		return (NULL);
	len = ft_line_len(str_ac) + 1;
	if (!len)
		return (NULL);
	line = ft_calloc(len, sizeof(char));
	while (str_ac[i] != '\0' && str_ac[i] != '\n')
	{
		line[i] = str_ac[i];
		i++;
	}
	if (str_ac[i] != '\0' && str_ac[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_clear_memory(char *str_ac)
{
	size_t	i;
	size_t	j;
	char	*new_line;

	i = 0;
	j = 0;
	while (str_ac[i] != '\n' && str_ac[i])
		i++;
	if (str_ac[i] == '\0')
	{
		free(str_ac);
		return (NULL);
	}
	new_line = ft_calloc(ft_strlen(str_ac) - i + 1, sizeof(char));
	i++;
	while (str_ac[i] != '\0')
		new_line[j++] = str_ac[i++];
	free(str_ac);
	if (new_line[0] == '\0')
	{
		free(new_line);
		return (NULL);
	}
	return (new_line);
}

/**
 * @brief Get the next line object from a file descriptor (fd) and returns it
 * 		  as a string.
 * 
 * @param fd -> file descriptor
 * @return char* -> The line that has been read. NULL if there is nothing else
 * 				   to read or an error has occurred.
 */
char	*get_next_line(int fd)
{
	static char	*str_ac;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
	{
		if (str_ac != NULL)
		{
			free(str_ac);
			str_ac = NULL;
		}
		return (NULL);
	}
	str_ac = ft_find_char(fd, str_ac);
	line = ft_get_line(str_ac);
	str_ac = ft_clear_memory(str_ac);
	return (line);
}
