/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:44:14 by palucena          #+#    #+#             */
/*   Updated: 2023/11/06 16:53:29 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef enum e_oken
{
	CMD = 0, //  0
	ARG, //  1
	PIPE, //  2
	REDIR_IN, //  3 <
	REDIR_OUT, //  4 >
	REDIR_HEREDOC, //  5 <<
	REDIR_APPEND, //  6 >>
	REDIR_FILEIN, //  7
	REDIR_FILEOUT, //  8
}	t_oken;

typedef struct s_lx
{
	char			*content;
	int				token;
	struct s_lx		*next;
}	t_lx;

typedef struct s_ps
{
	char		*cmd;
	char		**args;
	int			infile;
	int			outfile;
	struct s_ps	*next;
}	t_ps;

#endif