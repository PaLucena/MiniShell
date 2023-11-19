/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:08:23 by palucena          #+#    #+#             */
/*   Updated: 2023/11/15 16:43:27 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_info *info, char **args)
{
	int	i;

	i = 0;
	while (args[i] && ft_strncmp(args[i], "-n", 2) == 0)
		i++;
	while (args[i])
	{
		ft_putstr_fd(args[i], info->par->outfile);
		if (args[++i])
			write(info->par->outfile, " ", 1);
	}
	if (!args[0] || (args[0] && ft_strcmp(args[0], "-n") != 0))
		write(info->par->outfile, "\n", 1);
	info->status = 0;
}
