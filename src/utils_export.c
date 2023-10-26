/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:24:55 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/26 21:10:56 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_putenv(char *key, char *value, int fd)
{
	
	if (fd == 1)
		write(1, "declare -x ", 11);
	else
		write(1, "declare -xr ", 12);
	ft_putstr_fd(key, fd);
	write(1, "=", 1);
	ft_putstr_fd(value, fd);
	write(1, "\n", 1);
		
}

void	ft_put_noeq(t_cmd *c, char *key, int fd)
{
	while (c->list_env != NULL)
	{
		if (fd == 1)
			write(1, "declare -x ", 11);
		else
			write(1, "declare -xr ", 12);
		ft_putstr_fd(key, fd);
		write(1, "\n", 1);
		c->list_env = c->list_env->next;
	}
}

void	ft_put_eq_novalue(t_cmd *c, char *key, int fd)
{
	while (c->list_env != NULL)
	{
		if (fd == 1)
			write(1, "declare -x ", 11);
		else
			write(1, "declare -xr ", 12);
		ft_putstr_fd(key, fd);
		write(1, "=", 1);
		write(1, """", 1);
		write(1, "\n", 1);
		c->list_env = c->list_env->next;
	}
}
