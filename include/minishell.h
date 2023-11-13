/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:36:00 by palucena          #+#    #+#             */
/*   Updated: 2023/11/13 20:25:09 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/include/libft.h"
# include "minishell_structs.h"
# include "minishell_functions.h"

# include "readline/readline.h"
# include "readline/history.h"

# include <stdio.h>
# include <stdlib.h>

# include <fcntl.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# include <dirent.h>
# include <sys/stat.h>

# include <termios.h>

# include <curses.h>

# include <stdlib.h>

# include <limits.h>

#endif