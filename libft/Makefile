CC = gcc
NAME = libft.a
CFLAGS = -g -Wall -Werror -Wextra
LIB = ar rcs
FILES = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c\
		ft_isdigit.c ft_memchr.c ft_memcpy.c ft_memset.c\
		ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_memcmp.c ft_strnstr.c\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_memmove.c\
		ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c\
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_printf.c\
		print_char.c print_hexa.c print_str.c get_next_line_bonus.c get_next_line.c\
		get_next_line_utils.c ft_strcmp.c ft_atol.c ft_swap.c ft_lstswap.c\
		ft_strndup.c
		
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

bonus: $(OBJS) 
	$(LIB) $(NAME) $(OBJS) 

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME) 
re: fclean all
.PHONY : all re fclean clean