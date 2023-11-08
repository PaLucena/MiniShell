/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:18:22 by palucena          #+#    #+#             */
/*   Updated: 2023/11/08 10:59:25 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_builtin(char	*cmd)
{
	if (ft_strcmp(cmd, "echo"))
		return (true);
	else if (ft_strcmp(cmd, "cd"))
		return (true);
	else if (ft_strcmp(cmd, "pwd"))
		return (true);
	else if (ft_strcmp(cmd, "export"))
		return (true);
	else if (ft_strcmp(cmd, "unset"))
		return (true);
	else if (ft_strcmp(cmd, "env"))
		return (true);
	else if (ft_strcmp(cmd, "exit"))
		return (true);
	else
		return (false);
}
