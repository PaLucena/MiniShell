/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:44:14 by palucena          #+#    #+#             */
/*   Updated: 2023/10/19 18:07:15 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef enum e_tokens
{
	CMD = 0,
	ARG,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_AP,
	REDIR_HE,
	REDIR_FILEIN,
	REDIR_FILEOUT,
}	t_tokens;

typedef struct s_lexic_list
{
	int				token;
	char			*content;
	struct s_lex	*next;
}	t_lx;

#endif