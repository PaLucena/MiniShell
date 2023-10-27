/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:53:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/27 21:10:39 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_putenv(t_cmd *c, int fd)
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
		if (fd == 1)
			write(1, "declare -x ", 11);
		else
			write(1, "declare -xr ", 12);
		ft_putstr_fd(key, fd);
		write(1, "=", 1);
		if (*c->list_env->value == '\0')
			write(1, """", 1);
		else
			ft_putstr_fd(value, fd);
		write(1, "\n", 1);
		c->list_env = c->list_env->next;
	}
	write(1, "\n", 1);
}

void copy_env_list(t_cmd *c)
{
    int len = ft_strlen(c->list_env);
    
    c->sorted_list = (t_env *)malloc(sizeof(t_env) * len);
    if (!c->sorted_list)
        ft_error(1, "no se pudo crear malloc sorted_list");

    for (int i = 0; i < len; i++)
    {
        c->sorted_list[i] = (t_env *)malloc(sizeof(t_env) * ft_strlen(c->list_env[i]));
        if (!c->sorted_list[i])
            ft_error(1, "no se pudo crear malloc sorted_list[i]");
        
        // Copiar los elementos de la lista_env en sorted_list
        strcpy(c->sorted_list[i], c->list_env[i]);
    }
}

void	print_sorted_list(t_cmd *c)
{
	int len = ft_strlen((const char *)*c->list_env);
	for (int i = 0; i < len; i++)
	{
		printf("Elemento %d: %s\n", i, c->sorted_list[i]);
	}
}
