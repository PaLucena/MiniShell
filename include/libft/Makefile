# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 19:17:24 by rdelicad          #+#    #+#              #
#    Updated: 2023/11/08 14:24:09 by palucena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Colors ---

BOLD      := \033[1m
BLACK     := \033[30;1m
RED       := \033[31;1m
GREEN     := \033[32;1m
YELLOW    := \033[33;1m
BLUE      := \033[34;1m
MAGENTA   := \033[35;1m
CYAN      := \033[36;1m
WHITE     := \033[37;1m
RESET     := \033[0m

# --- Name & flags ---

NAME      := libft.a

CC        := gcc

LIB		:= ar rcs

CFLAGS    := -g -Wall -Wextra -Werror


# --- Files ---

SRCS := ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c\
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
		ft_strcspn.c ft_matfree.c ft_error.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

OBJS_DIR = obj


# --- Rules ---


$(NAME): $(OBJS_DIR) $(OBJS)
	@$(LIB) $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"

$(OBJS_DIR):
	mkdir -p $@

$(OBJS) : obj/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJS)
	$(LIB) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) 
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"

fclean:
	@rm -f $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"
	

re: fclean all

.PHONY: all re fclean clean
