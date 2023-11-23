/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:53:34 by rdelicad          #+#    #+#             */
/*   Updated: 2023/11/23 22:33:17 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Color definitions */
# define BOLD "\033[1m"
# define BLACK "\033[30;1m"
# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define BLUE "\033[34;1m"
# define MAGENTA "\033[35;1m"
# define CYAN "\033[36;1m"
# define WHITE "\033[37;1m"
# define RESET "\033[0m"

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <readline/readline.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_memmove(void *s1, const void *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
long				ft_atol(const char *str);
void				ft_swap(int *a, int *b);
size_t				ft_strcspn(const char *s, const char *reject);
void				ft_matfree(char **str);
void				ft_error(int fd, char *msn);
int					ft_str_isdigit(char *str);
char				*ft_frankestein(char *base, char *limb, int start, int end);

/*
** libft_Bonus
*/

typedef struct s_list
{
	int				block;
	int				costb;
	int				costa;
	int				cost_total;
	int				target;
	int				*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstswap(t_list **stack);

/**
 * ft_printf
 */

int					print_char(int c);
int					print_str(char *str);
int					ft_printf(char const *format, ...);
int					print_hexa(unsigned long long ptr);

/**
 * get_next_line
 */

char				*get_next_line(int fd);
int					ftg_strchr(char *s);
char				*ftg_strjoin(char *s1, char *s2);
int					ftg_strlen(char *s);
void				*ftg_calloc(size_t count, size_t size);
void				ftg_bzero(void *s, size_t n);

/**
 * get_next_line_bonus
 */

char				*get_next_line_bonus(int fd);

#endif
