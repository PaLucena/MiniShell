/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:15:28 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/19 00:12:40 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = c;
	while (*s != '\0')
	{
		if (*s == a)
			return ((char *)s);
		s++;
	}
	if (a == '\0')
		return ((char *)s);
	return (0);
}

int	len_envp(char **envp)
{
	int	len;

	len = 0;
	while (envp[len] != NULL)
		len++;
	return (len);
}

char 	**create_copy_array_envp(char **envp, int len)
{
	char	**copy_envp;
	int		i;

	copy_envp = malloc(sizeof(char *) * (len));
	if (!copy_envp)
		return (free(copy_envp), NULL);
	i = 0;
	while (i < len)
	{
		copy_envp[i] = envp[i];
		i++;
	}
	//copy_envp[i] = NULL;
	return (copy_envp);
}

void	ft_envp(char **envp)
{
	int	i;
	char **aux;

	i = 0;
	aux = create_copy_array_envp(envp, len_envp(envp));
	while (aux[i++] != NULL)
		printf("%s\n", aux[i]);
	//ft_split(envp, '\n');
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	//ft_envp(envp);
	int i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}