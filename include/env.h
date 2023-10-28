/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:10:00 by rdelicad          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< Updated upstream
/*   Updated: 2023/10/26 21:37:34 by rdelicad         ###   ########.fr       */
=======
/*   Updated: 2023/10/27 21:02:44 by rdelicad         ###   ########.fr       */
>>>>>>> Stashed changes
=======
/*   Updated: 2023/10/28 12:10:50 by rdelicad         ###   ########.fr       */
>>>>>>> 366fca702b01308f80b2e9b454d37d54837aa2ef
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_
# define ENV_

# include "../libft/include/libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_command
{
	t_env			*list_env;
	t_env			*sorted_list;
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
void				ft_free_list(t_cmd *c);

/* env.c */
void				ft_env(t_cmd *c);

/* export.c */
void				ft_export(t_cmd *c);
<<<<<<< HEAD
void				equal_print_env(t_cmd *c);
void				no_equal_sign(t_cmd *c);

/* utils_export.c */
<<<<<<< Updated upstream
void				ft_putenv(t_cmd *c, int fd);
void				ft_put_noeq(t_cmd *c, char *key, char *value, int fd);
void				ft_put_eq_novalue(t_cmd *c, char *key, char *value, int fd);
=======
void				ft_value_zero(t_cmd *c, char *key, char *value, int fd);
void				copy_env_list(t_cmd *c);
void				sort_env_list(t_cmd *c);
void				print_sorted_list(t_cmd *c);
>>>>>>> Stashed changes

=======
void				normal_export(t_cmd *c);
void				equal_sign_env(t_cmd *c);
void				no_equal_sign_env(t_cmd *c);
void				ft_putenv(t_cmd *c, char *key, char *value, int fd);

/* utils_export.c */
void				ft_value_zero(t_cmd *c, char *key, char *value, int fd);
void				ft_lst_swap(t_env *node_a, t_env *node_b);
void				sorted_list_env(t_env **env_list);
>>>>>>> 366fca702b01308f80b2e9b454d37d54837aa2ef
#endif
