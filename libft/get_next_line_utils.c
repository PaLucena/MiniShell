/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:32:29 by rdelicad          #+#    #+#             */
/*   Updated: 2023/06/02 19:28:41 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ftg_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*temp;
	int		s1_len;
	int		s2_len;

	if (s1 == NULL)
		s1 = ftg_calloc(1, 1);
	if (!s1)
		return (NULL);
	s1_len = ftg_strlen(s1);
	s2_len = ftg_strlen(s2);
	str = ftg_calloc(s1_len + s2_len + 1, 1);
	if (!str)
		return (free(s1), s1 = NULL, NULL);
	temp = str;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	free(s1 - s1_len);
	return (str);
}

int	ftg_strlen(char *s)
{
	int	n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}

int	ftg_strchr(char *s)
{
	if (s == NULL)
		return (0);
	while (*s != '\n' && *s)
		s++;
	return (*s == '\n');
}

void	*ftg_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ftg_bzero(ptr, count * size);
	return (ptr);
}

void	ftg_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}
