/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:11:25 by palucena          #+#    #+#             */
/*   Updated: 2023/11/08 15:00:04 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FUNCTIONS_H
# define MINISHELL_FUNCTIONS_H

# include "minishell_structs.h"

////////// lexer.c //////////
char	*l_get_quote(char *str, int start);
char	*l_get_word(char *str, int start);
char	*l_get_content(char *input, int i);
t_lx	*l_fill_lx(char *input);

////////// l_token.c /////////
void	l_add_back(t_lx **lst, t_lx *new);
void	l_tokenizer(t_lx *lx);

////////// parser.c //////////
t_ps	*p_fill_ps(t_lx *lex, t_ps *par);

////////// parser.c //////////
void	ft_execute(t_info *info);

////////// utils.c //////////
bool	check_builtin(char	*cmd);

////////// free.c //////////
void	free_lexer(t_lx *lex);
void	free_parser(t_ps *par);
void	ft_free(char **str);

/* leaks.c */
void				leaks(void);
char				*ft_strldup(char const *s1, size_t n);

/* b_env_init.c */
t_cmd				*init_struct(void);
int					len_envp(char **envp);
void				create_list_env(t_cmd *c, char **arr_env, int len_envp);
void				create_path(t_cmd *c);

/* builtins.c */
void				ft_builtins(t_info *i);

/* utils_list.c */
void				ft_lstadd_back_env(t_env **lst, t_env *new);
t_env				*ft_lstnew_env(char *key, char *value);
void				ft_add_new_env(t_cmd *c);
void				ft_free_list(t_env *list);
void				ft_free_node(t_env *node);

/* env.c */
void				ft_env(t_cmd *c);
void				env_finish_position(t_env **list);

/* export.c */
void				ft_export(t_cmd *c);
void				equal_sign_env(t_cmd *c);
void				no_equal_sign_env(t_cmd *c);
void				print_export(t_cmd *c);
void				ft_putenv(char *key, char *value, int equal, int fd);

/* utils_export.c */
int					check_argv_exp(t_cmd *c);
void				ft_value_zero(char *key, int equal, int fd);
void				ft_value_sign(char *value, int fd);
void				sorted_list_env(t_env **list_env);
void				ft_swap_node(t_env *a, t_env *b);

/* utils_export1.c */
void				yes_value(t_cmd *c);
void				no_value(t_cmd *c);
int					check_spaces(char *str);
void				check_env_repeated(t_cmd *c);
void				separate_env(t_cmd *c);

/* utils_export2.c */
void				argv_export(t_info *i);
void				add_var_export(t_cmd *c);

/* unset.c */
void				ft_unset(t_env **list, char *env);
void				top_the_list(t_env **list, t_env *new);
void				middle_the_list(t_env *new);
void				finish_the_list(t_env *new);

/* pwd.c */
void				ft_pwd(t_cmd *c);

/* cd.c */
void				ft_cd(t_cmd *c);
void				changer_pwd_env(t_cmd *c);
void				changer_oldpwd_env(t_cmd *c, char *oldpwd);
char				*get_pwd(t_cmd *c);

/* utils.cd.c */
char				*get_directory_path(t_cmd *c);
char				*get_parent_directory(char *path);

/* exit.c */
void				ft_exit(t_cmd *c);

#endif