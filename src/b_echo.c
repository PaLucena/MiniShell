/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:08:23 by palucena          #+#    #+#             */
/*   Updated: 2023/11/12 22:26:02 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_ps *par)
{
	int	i;

	i = 0;
	if (par->args[0] && ft_strcmp(par->args[0], "-n") == 0)
		i++;
	while (par->args[i])
	{
		ft_putstr_fd(par->args[i], par->outfile);
		if (par->args[++i])
			write(par->outfile, " ", 1);
	}
	if (!par->args[0] || (par->args[0] && ft_strcmp(par->args[0], "-n") != 0))
		write(par->outfile, "\n", 1);
}
