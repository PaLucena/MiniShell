/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_cd1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:51:54 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/27 10:52:07 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_new_line(char *str)
{
	if (str[0] != '\0')
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
	else
	{
		write(1, str, ft_strlen(str));
	}
}