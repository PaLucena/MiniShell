/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_leaks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:41:40 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/08 13:05:44 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	leaks(void)
{
	system ("leaks -q mini");
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
