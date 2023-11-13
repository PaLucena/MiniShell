/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:11:39 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/13 20:39:21 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_manager(t_info *i)
{
	(void)i;
	struct sigaction	action;

	action.sa_sigaction = handler_sigusr;
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL); //Ctrl + C
	signal(SIGQUIT, SIG_IGN);//Ctrl + \/
	
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;

	if (signum == SIGINT)
	{
		return;
		rl_on_new_line();
		rl_redisplay();
		write(1, "   \n", 1);
		rl_on_new_line();
		//rl_replace_line("", 0);
		rl_redisplay();
	}
}