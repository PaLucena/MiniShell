/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:48:10 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/23 20:15:49 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_free_list(t_cmd *c)
{
	while (c->list_env != NULL)
	{
		free(c->list_env->key);
		free(c->list_env->value);
		c->list_env = c->list_env->next;
	}
}

void	ft_matfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_env	*ft_lstnew(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->value = strdup(value);
	new_node->key = strdup(key);
	new_node->equal = 0;
	new_node->next = NULL;
	if (!new_node->value || !new_node->key)
	{
		free(new_node->value);
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	return (new_node);
}

void	add_env(t_cmd *c)
{
	t_env *new_node;

	new_node = ft_lstnew(c->key, c->value);
	ft_lstadd_back(&(c->list_env), new_node);
	c->environment = NULL;
	ft_export(c);
}
