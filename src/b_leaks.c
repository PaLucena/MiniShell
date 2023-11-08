/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_leaks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:41:40 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/08 14:54:40 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	leaks(void)
{
	system ("leaks -q minishell");
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
