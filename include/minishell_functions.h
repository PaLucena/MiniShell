/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:11:25 by palucena          #+#    #+#             */
/*   Updated: 2023/11/22 13:10:46 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FUNCTIONS_H
# define MINISHELL_FUNCTIONS_H

# include "minishell_structs.h"

////////// l_start.c //////////
char	*l_get_quote(char *str, int start, t_info *info);
char	*l_get_word(char *str, int start, t_info *info);
char	*l_get_content(char *input, int i, t_info *info);
t_lx	*l_fill_lx(char *input, t_info *info);

////////// l_token.c /////////
int		l_check_tokens(t_lx *lex);
void	l_add_back(t_lx **lst, t_lx *new);
int		l_tokenizer(t_lx *lx, int i);

////////// l_env.c /////////
bool	l_is_env(char *str, t_info *info);
char	*l_get_env(char *str, t_info *info);

////////// l_utils.c /////////
bool	l_is_finished(char start, char curr);
int		l_check_tokens(t_lx *lex);
bool	l_check_syntax(char *str, t_info *info);

////////// l_next.c /////////
int		l_get_next_i(char *str, int i);

////////// p_start.c //////////
t_ps	*p_fill_ps(t_lx *lex, t_ps *par);

////////// p_utils.c //////////
int		ft_heredoc(char *limiter);
int		p_open(t_lx *lex);
t_lx	*p_fill_arg(char **args, t_lx *lex);

////////// error.c //////////
void	ft_error_msg(t_info *info, int e);

////////// exec.c //////////
void	ft_execute(t_info *info);

////////// free.c //////////
void	free_lexer(t_lx *lex);
void	free_parser(t_ps *par);
void	ft_free(char **str);
void	free_info(t_info *info);

/* leaks.c */
void	leaks(void);
char	*ft_strldup(char const *s1, size_t n);
void	free_command(t_info *i);

/* b_env_init.c */
t_cmd	*init_struct(void);
int		len_envp(char **envp);
void	create_list_env(t_cmd *c, char **arr_env, int len_envp);
void	changer_env_cmd(t_cmd *c);
void	ft_shell_lvl(t_env *list_env);

/* builtins.c */
bool	check_builtin(char *cmd);
void	ft_builtins(t_info *i);

/* utils_list.c */
void	ft_lstadd_back_env(t_env **lst, t_env *new);
t_env	*ft_lstnew_env(char *key, char *value);
void	ft_add_new_env(t_cmd *c);
void	ft_free_list(t_env *list);
void	ft_free_node(t_env *node);

/* utils_cd.c*/
char	*get_directory_path(t_info *i);
char	*get_parent_directory(char *path);
void	env_error(char *env);
int		no_clear_home(t_info *i, char *key);
void	check_oldpwd(t_info *i);

/* env.c */
void	ft_env(t_info *i);
void	env_finish_position(t_env **list);
void	env_argv(t_info *i);
void	clear_value_oldpwd(t_cmd *c);

/* export.c */
void	ft_export(t_info *i);
void	equal_sign_env(t_cmd *c);
void	no_equal_sign_env(t_cmd *c);
void	print_export(t_cmd *c);
void	ft_putenv(char *key, char *value, int equal, int fd);

/* utils_export.c */
int		check_argv_exp(t_cmd *c);
void	ft_value_zero(char *key, char *value, int equal, int fd);
void	ft_value_sign(char *value, int fd);
void	sorted_list_env(t_env **list_env);
void	ft_swap_node(t_env *a, t_env *b);

/* utils_export1.c */
void	yes_value(t_cmd *c);
void	no_value(t_cmd *c);
int		check_spaces(char *str);
void	check_env_repeated(t_cmd *c);
void	separate_env(t_cmd *c);

/* utils_export2.c */
void	argv_export(t_info *i);
void	add_var_export(t_cmd *c);

/* unset.c */
void	ft_unset(t_info *i);
int		top_the_list(t_info *i);
int		middle_the_list(t_info *i);
int		finish_the_list(t_info *i);

/* pwd.c */
void	ft_pwd(t_cmd *c);

/* cd.c */
void	ft_cd(t_info *i);
void	changer_pwd_env(t_cmd *c);
void	changer_oldpwd_env(t_cmd *c, char *oldpwd);
char	*get_pwd(t_cmd *c);
int		clear_env(t_info *i);

/* utils.cd.c */
char	*get_directory_path(t_info *i);
char	*get_parent_directory(char *path);

/* echo.c */
void	ft_echo(t_info *info, char **args);

/* exit.c */
void	ft_exit(t_info *i);
void	exit_no_digit(t_info *i);
void	exit_many_arguments(t_info *i);
void	exit_number(t_info *i);

/* signal.c */
void	signal_manager(t_info *i);
void	handler_sigusr(int signum);
void	control_d(t_info *i);

/* search_path.c */
int		search_path(t_info *i);

#endif