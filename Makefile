NAME = minishell

CC = gcc -g
FLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRC_PATH = src/
SRC = b_leaks.c b_env_init.c b_utils_list.c b_env.c b_export.c\
		b_utils_export.c b_utils_export1.c b_utils_export2.c b_unset.c b_pwd.c\
		b_builtins.c b_cd.c b_echo.c b_utils_cd.c b_exit.c\
		s_signal.c s_shell_level.c\
		main.c free.c\
		l_start.c l_token.c l_env.c l_utils.c l_next.c\
		p_start.c p_utils.c\
		exec.c error.c\
		search_path.c\

OBJ_PATH = objs/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

INC = include
LIB = include/libft/libft.a

HEADERS	= -I ./include -I ~/.brew/opt/readline/include

SYS = $(shel uname -s)

#ifeq ($(SYS), Darwin)
INCLUDES = -L ~/.brew/opt/readline/lib -lreadline 
#endif

#//= Colors =//#
BOLD    := \033[1m
BLACK   := \033[30;1m
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET   := \033[0m

all: libft $(NAME)

$(NAME): $(OBJ)
	@ gcc $(FLAGS) $(OBJ) $(LIB) $(HEADERS) $(INCLUDES) -o $(NAME)
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