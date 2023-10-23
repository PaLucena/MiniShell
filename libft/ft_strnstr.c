/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:59:11 by rdelicad          #+#    #+#             */
/*   Updated: 2023/04/26 12:28:53 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (*big && i < len)
	{
		j = 0;
		while (*(big + j) == *(little + j) && *(big + j) && (i + j) < len)
			j++;
		if (*(little + j) == '\0')
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
