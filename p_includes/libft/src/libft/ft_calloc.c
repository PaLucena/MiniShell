/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:18:43 by palucena          #+#    #+#             */
/*   Updated: 2023/07/13 16:28:42 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * @brief Allocates memory for an array of nb elements of size bytes each and 
 *  	  returns a pointer to the allocated memory. The memory is set to zero.
 * 
 * @param nb -> number of elements
 * @param size -> size of each element
 * @return void* -> pointer to the allocated memory
 */
void	*ft_calloc(size_t nb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(size * nb);
	if (!ptr)
		return (0);
	i = 0;
	while (i < (nb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
