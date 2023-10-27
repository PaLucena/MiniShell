/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:53:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/27 17:59:01 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_value_zero(t_cmd *c, char *key, char *value, int fd)
{
	(void)value;
	char str[2] = "\"\"";

	if (fd == 1)
		write(1, "declare -x ", 11);
	else
		write(1, "declare -xr ", 12);
	ft_putstr_fd(key, fd);
	if (c->argv_env != NULL && ft_strchr(c->argv_env, '='))
	{
		write(1, "=", 1);
		write(1, str, 2);
	}
	write(1, "\n", 1);
}