/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:57:26 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:03:48 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	a;

	a = c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*(s + len) == a)
		{
			return ((char *)s + len);
		}
		len--;
	}
	return (NULL);
}
