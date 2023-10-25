/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:55:40 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:03 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ to the content
 * 
 * @param lst -> The address of a pointer to an element.1
 * @param f -> The address of the function used to iterate on the list.
 * @param del -> The address of the function used to delete the content of an
 * 				 element
 * @return t_list* -> The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*actual;

	if (!lst)
		return (0);
	new = 0;
	while (lst)
	{
		actual = ft_lstnew(f(lst->content));
		if (actual)
		{
			ft_lstadd_back(&new, actual);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&new, del);
			return (0);
		}
	}
	return (new);
}
