/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:48:10 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/26 09:16:04 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_free_list(t_cmd *c)
{
	t_env	*curr;
	t_env	*next;

	curr = c->list_env;
	while (curr != NULL)
	{
		free(curr->key);
		free(curr->value);
		next = curr->next;
		free(curr);
		curr = next;
	}
	/* free(c->key);
	free(c->value); */
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
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

t_env	*ft_lstnew_env(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->value = ft_strdup(value);
	new_node->key = ft_strdup(key);
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

void	ft_add_new_env(t_cmd *c)
{
	t_env *new_node;
	char	*key;
	char	*value;

	key = c->key;
	value = c->value;
	new_node = ft_lstnew_env(key, value);
	ft_lstadd_back_env(&(c->list_env), new_node);
	c->argv_env = NULL;
	ft_export(c);
	free(new_node);
	free(c->key);
	free(c->value);
}
