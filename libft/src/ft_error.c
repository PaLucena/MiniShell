/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:23:10 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/27 20:23:56 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_error(int fd, char *msn)
{
	const char	*error;
	const char	*reset;

	error = "Error: ";
	reset = "\n";
	write (fd, error, ft_strlen(error));
	write (fd, msn, ft_strlen(msn));
	write (fd, reset, ft_strlen(reset));
}
