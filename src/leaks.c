/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:41:40 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 19:33:11 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	leaks(void)
{
	system ("leaks -q a.out");
}

char	*ft_strldup(char const *s1, size_t n)
{
	char	*ptr;

	ptr = (char *)malloc(n + 1);
	if (!ptr)
		return (NULL);
	memcpy(ptr, s1, n);
	ptr[n] = '\0';
	return (ptr);
}
