/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:31:40 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/28 15:52:08 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_error(int fd, char *msn)
{
	const char	*error;
	const char	*reset;

	error = RED "Error: " RESET CYAN;
	reset = RESET "\n";
	write (fd, error, ft_strlen(error));
	write (fd, msn, ft_strlen(msn));
	write (fd, reset, ft_strlen(reset));
}
