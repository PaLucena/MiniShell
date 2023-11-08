/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:11:25 by palucena          #+#    #+#             */
/*   Updated: 2023/11/08 00:35:28 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FUNCTIONS_H
# define MINISHELL_FUNCTIONS_H

# include "minishell_structs.h"

////////// lexer.c //////////
char	*l_get_quote(char *str, int start);
char	*l_get_word(char *str, int start);
char	*l_get_content(char *input, int i);
t_lx	*l_fill_lx(char *input);

////////// l_token.c /////////
void	l_add_back(t_lx **lst, t_lx *new);
void	l_tokenizer(t_lx *lx);

////////// parser.c //////////
t_ps	*p_fill_ps(t_lx *lex, t_ps *par);

////////// parser.c //////////
void	ft_execute(t_ps *par);

////////// utils.c //////////
bool	check_builtin(char	*cmd);

////////// free.c //////////
void	free_lexer(t_lx *lex);
void	free_parser(t_ps *par);

#endif