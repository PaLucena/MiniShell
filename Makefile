NAME = minishell

CC = gcc -g
FLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRC_PATH = src/
SRC = main.c #todos los archivos.c
OBJ_PATH = objs/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

INC = -I includes/
LIB = -I includes/libft/libft.a

HEADERS	= -I $(LIB)/include/ -I ./include

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

all: $(NAME)

$(NAME): $(OBJ)
	@ gcc $(FLAGS) $(OBJ) -lreadline -o
	@ echo "\n\t\t$(GREEN)$(BOLD)----MiniShell compiled----\n$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@ mkdir -p  $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@

clean:
	@ rm -rf $(OBJ_PATH)
	@ echo "\n\t\t\t$(RED)$(BOLD)Cleaning...\n$(RESET)"

fclean: clean
	@ rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re