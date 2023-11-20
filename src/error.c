/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:50:39 by palucena          #+#    #+#             */
/*   Updated: 2023/11/20 17:29:57 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_t(int e)
{
	if (e == 2)
		return ("|");
	else if (e == 3)
		return ("<");
	else if (e == 4)
		return (">");
	else if (e == 5)
		return ("<<");
	else if (e == 6)
		return (">>");
	else if (e == 7)
		return ("newline");
	return (NULL);
}

void	ft_error_msg(t_info *info, int e)
{
	char	*token;

	token = get_t(e);
	if (token)
	{
		printf("minishell: syntax error near unexpected token `%s'\n", token);
		info->status = 258;
	}
	if (info && info->status == 127)
		printf("minishell: %s: command not found\n", info->par->cmd);
	else if (info && info->status == 11)
	{
		printf("minishell: %s: no such file or directory\n", info->par->cmd);
		info->status = 127;
	}
}
