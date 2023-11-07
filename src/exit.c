/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:27:20 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/07 20:06:00 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_exit(t_cmd *c)
{
	if (c->argv_exit == NULL)
	{
		ft_putstr_fd("exit", 1);
		exit (0);
	}
	else if (c->argv_exit != NULL)
	{
		printf("%s\n", c->argv_exit);
		if (ft_atoi(c->argv_exit) >= 0 && ft_atoi(c->argv_env) <= 255)
			ft_putstr_fd("exit", ft_atoi(c->argv_exit));
		exit (ft_atoi(c->argv_exit));
	}
}