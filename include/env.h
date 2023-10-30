/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:00:10 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/30 16:57:10 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_
# define ENV_

# include "../libft/include/libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	int				equal;
	struct s_env	*next;
}					t_env;

typedef struct s_command
{
	t_env			*list_env;
	char			*argv_env;
	char			*key;
	char			*value;
	char			*equal_sign;
}					t_cmd;

/* leaks.c */
void				leaks(void);
char				*ft_strldup(char const *s1, size_t n);

/* main.c */
void				init_struct(t_cmd *c);
int					len_envp(char **envp);
void				create_list_env(t_cmd *c, char **arr_env, int len_envp);

/* utils_list.c */
void				ft_lstadd_back_env(t_env **lst, t_env *new);
t_env				*ft_lstnew_env(char *key, char *value);
void				ft_add_new_env(t_cmd *c);
void				ft_free_list(t_env *list);
void				ft_free_node(t_env *node);

/* env.c */
void				ft_env(t_cmd *c);

/* export.c */
void				ft_export(t_cmd *c);
void				equal_sign_env(t_cmd *c);
void				no_equal_sign_env(t_cmd *c);
void				normal_export(t_cmd *c);
void				ft_putenv(t_cmd *c, char *key, char *value, int fd);

/* utils_export.c */
int					check_argv_exp(t_cmd *c);
void				ft_value_zero(t_cmd *c, char *key, char *value, int fd);
void				ft_value_sign(char *value, int fd);
void				sorted_list_env(t_env **list_env);
void				ft_swap_node(t_env *a, t_env *b);

#endif
