/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:54:06 by palucena          #+#    #+#             */
/*   Updated: 2023/10/24 15:02:13 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Adds the new element at the end of the list.
 * 
 * @param lst -> address of a pointer to the first link of a list
 * @param new -> address of a pointer to the element to be added to the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*actual;

	if (*lst)
	{
		actual = ft_lstlast(*lst);
		actual->next = new;
	}
	else
		*lst = new;
}
