/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:19:37 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:40:10 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Counts the number of elements in a list.
 * 
 * @param lst -> The beginning of the list.
 * @return int -> Length of the list.
 */
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*actual;

	if (!lst)
		return (0);
	i = 1;
	actual = lst;
	while (actual->next)
	{
		i++;
		actual = actual->next;
	}
	return (i);
}
