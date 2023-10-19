NAME = minishell

CC = gcc -g
FLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC_PATH = src/
SRC = main.c\
		lexer.c l_split.c l_split_fill.c
OBJ_PATH = objs/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

INC = includes
LIB = includes/libft/libft.a

HEADERS	= -I ./includes

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

all: libft $(NAME)

$(NAME): $(OBJ)
	@ gcc $(FLAGS) $(OBJ) $(LIB) $(HEADERS) -lreadline -o $(NAME)
	@ echo "\n\t\t$(GREEN)$(BOLD)----MiniShell compiled----\n$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@ mkdir -p  $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

libft:
	@ make -C $(INC)/libft

clean:
	@ rm -rf $(OBJ_PATH)
	@ make -C $(INC)/libft clean
	@ echo "\n\t\t\t$(RED)$(BOLD)Cleaning...\n$(RESET)"

fclean: clean
	@ rm -rf $(NAME)
	@ make -C $(INC)/libft fclean

re: fclean all


.PHONY: all libft clean fclean re