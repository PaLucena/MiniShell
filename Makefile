# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 19:17:24 by rdelicad          #+#    #+#              #
#    Updated: 2023/10/31 19:42:02 by rdelicad         ###   ########.fr        #
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

NAME      := mini

CC        := gcc

CFLAGS    := -g -Wall -Wextra -Werror #-fsanitize=address

# --- Library ---

LIBFT_DIR	:= ./libft
LIBFT_PATH	:= $(LIBFT_DIR)/libft.a 

# --- Files ---

SRCS      := leaks.c main.c utils_list.c env.c export.c\
			utils_export.c utils_export1.c unset.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

OBJS_DIR = obj

# --- Rules ---


$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT_PATH)
	@echo "$(YELLOW)$(BOLD)Compiling minishel...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"

$(OBJS_DIR):
	mkdir -p $@

$(OBJS) : obj/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH):
	@make -s -C $(LIBFT_DIR)
	@make bonus -s -C $(LIBFT_DIR)

all: $(NAME)

clean:
	@echo "$(RED)$(BOLD)Cleaning objects from program...$(RESET)"
	@rm -f $(OBJS) 
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"

fclean:
	@echo "$(RED)$(BOLD)Cleaning all files from program...$(RESET)"
	@rm -f $(NAME) $(OBJS)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"
	

re: fclean all

.PHONY: all re fclean clean