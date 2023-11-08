/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD:p_includes/libft/src/printf/ft_putchar.c
/*   ft_putchar.c                                       :+:      :+:    :+:   */
=======
/*   print_char.c                                       :+:      :+:    :+:   */
>>>>>>> env:libft/src/print_char.c
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:p_includes/libft/src/printf/ft_putchar.c
/*   Created: 2023/04/29 19:54:48 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:42:13 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
=======
/*   Created: 2023/05/16 15:09:20 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 20:04:21 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	print_char(int c)
{
	return (write (1, &c, 1));
>>>>>>> env:libft/src/print_char.c
}
