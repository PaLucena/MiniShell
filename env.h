#ifndef ENV_
# define ENV_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	int				*equal;
	struct s_env	*next;
}					t_env;

/* command_env.c */
int					len_envp(char **envp);
char				**create_copy_array_envp(char **envp, int len);
t_env				*create_list_env(char **arr_env, int len_envp);
void				ft_envp(char **envp);

/* utils_env.c */
char				*ft_strchr(const char *s, int c);
void				ft_lstadd_back(t_env **lst, t_env *new);
t_env				*ft_lstnew(char *key, char *value);

#endif
