/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:10:00 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/24 19:47:21 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_
# define ENV_

# include "../libft/libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_command
{
	t_env			*list_env;
	char			*environment;
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
t_env				*create_list_env(t_cmd *c, char **arr_env, int len_envp);

/* utils_list.c */
void				ft_lstadd_back_env(t_env **lst, t_env *new);
t_env				*ft_lstnew_env(char *key, char *value);
void				ft_add_new_env(t_cmd *c);
void				ft_free_list(t_cmd *c);

/* command.c */
void				ft_export(t_cmd *c);
void				ft_env(t_cmd *c);
void				cases_for_equal_sign(t_cmd *c);

#endif
