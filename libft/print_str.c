/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:10:27 by rdelicad          #+#    #+#             */
/*   Updated: 2023/06/02 19:31:07 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(char *str)
{
	int	cont;

	if (!str)
		return (print_str("(null)"));
	cont = 0;
	while (*str)
	{
		print_char((int)*str);
		++str;
		++cont;
	}
	return (cont);
}
