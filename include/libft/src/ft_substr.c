/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:34:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:03:55 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		slen;
	char		*substr;
	int			max;

	slen = (int)ft_strlen(s);
	if (s == NULL )
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	if (len < (size_t)(slen - start))
		max = len;
	else
		max = slen - start;
	substr = (char *)malloc((max + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, max + 1);
	substr[max] = '\0';
	return (substr);
}
