/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:27:17 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/04 13:42:15 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_pwd(t_cmd *c)
{
	c->pwd = getcwd(NULL, 0);
	if (c->pwd == NULL)
	{
		perror("Error al obtener pwd");
		return ;
	}
	printf("%s\n", c->pwd);
}
