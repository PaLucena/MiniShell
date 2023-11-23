/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:27:20 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/23 22:07:54 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_info *i)
{
	if (i->par->args[0] == NULL)
	{
		ft_putstr_fd("exit\n", 1);
		i->status = 0;
		exit(0);
	}
	else if (!ft_str_isdigit(i->par->args[0]))
	{
		if ((i->par->args[0][0] != '-' && i->par->args[0][0] != '+'))
			exit_no_digit(i);
		else
			exit_number(i);
	}
	else if (i->par->args[1] != NULL)
		exit_many_arguments(i);
	else if (i->par->args[0] != NULL)
		exit_number(i);
}

void	exit_no_digit(t_info *i)
{
	ft_putstr_fd("exit", 1);
	write(1, "\n", 1);
	write(2, "minishell: exit: ", 17);
	write(2, i->par->args[0], ft_strlen(i->par->args[0]));
	write(2, ": numeric argument required", 27);
	write(1, "\n", 1);
	i->status = 255;
	exit(255);
}

void	exit_many_arguments(t_info *i)
{
	ft_putstr_fd("exit", 1);
	write(1, "\n", 1);
	write(2, "minishell: exit: ", 17);
	write(2, "too many arguments", 18);
	write(1, "\n", 1);
	i->status = 1;
}

void	exit_number(t_info *i)
{
	unsigned int	num;

	num = 0;
	if (ft_atol(i->par->args[0]) > INT_MAX
		|| ft_atol(i->par->args[0]) < INT_MIN)
		exit_no_digit(i);
	else if (ft_atoi(i->par->args[0]) < 0 && ft_atoi(i->par->args[0]) > 255)
	{
		num = abs(ft_atoi(i->par->args[0])) % 256;
		ft_putstr_fd("exit", 1);
		i->status = num;
		exit(num);
	}
	else
	{
		ft_putstr_fd("exit\n", 1);
		num = ft_atoi(i->par->args[0]);
		i->status = num;
		exit(num);
	}
}
