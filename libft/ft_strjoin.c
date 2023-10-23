/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:56:26 by rdelicad          #+#    #+#             */
/*   Updated: 2023/04/28 11:31:09 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	newstr = malloc((slen1 + slen2 + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s1, slen1 + 1);
	ft_strlcat(newstr, s2, slen1 + slen2 + 1);
	newstr[slen1 + slen2] = '\0';
	return (newstr);
}
