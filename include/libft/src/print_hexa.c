/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:20:31 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:04:26 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	print_hexa(unsigned long long ptr)
{
	char	*symbols;
	int		cont;

	cont = 0;
	symbols = "0123456789abcdef";
	if (ptr >= 16)
		cont += print_hexa(ptr / 16);
	print_char(symbols[ptr % 16]);
	cont++;
	return (cont);
}
