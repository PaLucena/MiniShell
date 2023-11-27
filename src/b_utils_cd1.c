/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_cd1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:51:54 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/27 13:14:13 by palucena         ###   ########.fr       */
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
