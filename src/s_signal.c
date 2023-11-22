/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:11:39 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/22 16:51:52 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_manager(t_info *i)
{
	(void)i;
	signal(SIGINT, handler_sigusr);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

void	handler_sigusr(int signum)
{
	(void)signum;
	{
		if (g_signal_detector == BASE)
		{
			rl_on_new_line();
			rl_redisplay();
			ft_putstr_fd("   \n", 1);
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		} 
		else if (g_signal_detector == MID_CMD)
		{
			rl_on_new_line();
			ft_putstr_fd("   \n", 1);
		} 
		if (g_signal_detector == HEREDOC)
		{
			ft_putstr_fd("   \n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	} 
}

void	control_d(t_info *i)
{
	(void)i;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("exit\n", 1);
	exit (0);
}
