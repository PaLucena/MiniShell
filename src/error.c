/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:50:39 by palucena          #+#    #+#             */
/*   Updated: 2023/11/15 19:15:17 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_msg(t_info *info, int e)
{
	if (e == -1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'", 1);
		info->status = 258;
	}
	else if (e == 1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'", 1);
		info->status = 258;
	}
}
