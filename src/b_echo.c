/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:08:23 by palucena          #+#    #+#             */
/*   Updated: 2023/11/27 18:17:38 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_arg(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (false);
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

void	ft_echo(t_info *info, char **args)
{
	int	i;

	i = 0;
	while (args[i] && check_arg(args[i]))
		i++;
	while (args[i])
	{
		ft_putstr_fd(args[i], info->par->outfile);
		if (args[++i])
			write(info->par->outfile, " ", 1);
	}
	if (!args[0] || (args[0] && ft_strncmp(args[0], "-n", 2) != 0))
		write(info->par->outfile, "\n", 1);
	info->status = 0;
}
