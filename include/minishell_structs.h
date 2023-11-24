/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:44:14 by palucena          #+#    #+#             */
/*   Updated: 2023/11/24 13:30:37 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

int	g_signal_detector;

typedef enum e_sig_detect
{
	BASE = 0,
	HEREDOC,
	HEREDOC_DAD,
	MID_CMD,
	CANCEL_EXEC,
}	t_sig_detect;

typedef enum e_oken
{
	CMD = 0,
	ARG,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_HEREDOC,
	REDIR_APPEND,
	REDIR_FILEIN,
	REDIR_FILEOUT,
}	t_oken;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				equal;
	struct s_env	*next;
}					t_env;

typedef struct s_cmd
{
	t_env			*list_env;
	t_env			*curr;
	char			*parent_dir;
	char			*argv_env;
	char			*argv_unset;
	char			*key;
	char			*value;
	char			*equal_sign;
	char			*pwd;
	char			*input;
}					t_cmd;

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

typedef struct s_info
{
	t_ps	*par;
	t_cmd	*c;
	int		status;
	int		n_cmds;
}	t_info;

#endif