/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:30:18 by palucena          #+#    #+#             */
/*   Updated: 2023/10/20 15:08:31 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	l_check_redir(char *word)
{
	if (ft_strcmp(word, "<"))
		return (REDIR_IN);
	else if (ft_strcmp(word, ">"))
		return (REDIR_OUT);
	else if (ft_strcmp(word, "<<"))
		return (REDIR_HEREDOC);
	else if (ft_strcmp(word, ">>"))
		return (REDIR_APPEND);
	return (0);
}

int	l_get_token(char **words, int i)
{
	if (ft_strcmp(words[i], "|"))
		return (PIPE);
	else if (l_check_redir(words[i]) != 0)
		return (l_check_redir(words[i]));
	else if (i == 0 || ft_strcmp(words[i - 1], "|"))
		return (CMD);
	else if (ft_strcmp(words[i - 1], "<"))
		return (REDIR_FILEIN);
	else if (ft_strcmp(words[i - 1], ">") || ft_strcmp(words[i - 1], "<"))
		return (REDIR_FILEOUT);
	else
		return (ARG);
}
