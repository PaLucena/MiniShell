/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:16:36 by rdelicad          #+#    #+#             */
/*   Updated: 2023/05/11 21:20:52 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_list;

	if (!lst)
		return (NULL);
	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = f(lst->content);
	if (lst->next)
	{
		new_list->next = ft_lstmap(lst->next, f, del);
		if (!new_list->next)
		{
			del(new_list->content);
			free(new_list);
			return (NULL);
		}
	}
	else
		new_list->next = NULL;
	return (new_list);
}
