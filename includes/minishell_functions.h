/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:11:25 by palucena          #+#    #+#             */
/*   Updated: 2023/10/19 13:31:14 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FUNCTIONS_H
# define MINISHELL_FUNCTIONS_H

# include "minishell_structs.h"

////////// lexer.c ////////// 
int		ft_lexer(t_lx **lex, char *input);

////////// l_split.c //////////
int		l_end_of_quote(char *str, int start); 
char	**l_split(char *input);

////////// l_split_fill.c ////////// 
char	*l_fill_quote(char *input, int start);
char	*l_fill_word(char *input, int start);

#endif