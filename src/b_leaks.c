/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_leaks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:41:40 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/25 19:24:51 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	free_command(t_info *i)
{
	ft_free_list(i->c->list_env);
	free(i->c);
}
