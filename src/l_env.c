/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:03:29 by palucena          #+#    #+#             */
/*   Updated: 2023/11/11 20:44:43 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	l_is_env(char *str, t_env *env)
{
	if (l_get_env(str, env) != NULL)
		return (true);
	return (false);
}

char	*l_get_env(char *str, t_env *env)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	while (str[++i])
	{
		if (str[i++] == '$')
		{
			j = 0;
			while (str[i + j] && str[i + j] != '$')
				j++;
			if ()
		}
	}
	return (NULL);

}
