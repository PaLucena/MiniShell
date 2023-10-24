/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:11:25 by palucena          #+#    #+#             */
/*   Updated: 2023/10/24 22:25:23 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FUNCTIONS_H
# define MINISHELL_FUNCTIONS_H

# include "minishell_structs.h"


////////// lexer.c ////////// 
char	**l_split(char *str);
t_lx	*ft_lexer(char *input);

////////// l_split.c //////////
int		l_skip_space(char *str, int i);
int		l_count_words(char *str);
int		l_end_of_quote(char *str, int start); 
char	*l_fill_quote(char *input, int start);
char	*l_fill_word(char *input, int start);

////////// l_split.c //////////
int		l_get_token(char **word, int i);
t_lx	*l_tokenkizer(char **words);


#endif