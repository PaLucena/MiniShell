/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:10:00 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/23 20:40:43 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_
# define ENV_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

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
	char			*environment;
	char			*key;
	char			*value;
}					t_cmd;

/* leaks.c */
void				leaks(void);

/* command_env.c */
void				ft_envp(t_cmd *c);
int					len_envp(char **envp);
t_env				*create_list_env(char **arr_env, int len_envp);

/* utils_env.c */
void				ft_lstadd_back(t_env **lst, t_env *new);
t_env				*ft_lstnew(char *key, char *value);
void				add_env(t_cmd *c);
void				ft_free_list(t_cmd *c);
void				ft_matfree(char **str);

/* command_export.c */
void				ft_export(t_cmd *c);

#endif
