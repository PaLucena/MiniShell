/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:20:51 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:00 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Returns the last element of the list.
 * 
 * @param lst -> The address of a pointer to an element.
 * @return t_list* -> The last element of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*actual;

	if (!lst)
		return (0);
	actual = lst;
	while (actual->next)
	{
		actual = actual->next;
	}
	return (actual);
}
