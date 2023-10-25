NAME = libft.a

SOURCE_LIBFT_PATH =		src/libft/
SOURCE_PRINTF_PATH =	src/printf/
SOURCE_GNL_PATH =		src/gnl/
SOURCE_OWN_PATH =		src/own/

SOURCE_LIBFT =		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
					ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
					ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
					ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
					ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
					ft_lstclear.c ft_lstiter.c ft_lstmap.c

SOURCE_PRINTF =		ft_printf.c ft_putchar.c ft_printchar.c ft_printstr.c ft_printptr.c ft_printdec.c ft_printunsigned.c ft_printhexa.c

SOURCE_GNL =		get_next_line.c get_next_line_utils.c

SOURCE_OWN =		ft_strcmp.c

OBJ_PATH =			objs/
OBJ_LIBFT_PATH =	$(OBJ_PATH)libft/
OBJ_PRINTF_PATH =	$(OBJ_PATH)printf/
OBJ_GNL_PATH =		$(OBJ_PATH)gnl/
OBJ_OWN_PATH =		$(OBJ_PATH)own/

OBJ_LIBFT =			$(addprefix $(OBJ_LIBFT_PATH), $(SOURCE_LIBFT:.c=.o))
OBJ_PRINTF =		$(addprefix $(OBJ_PRINTF_PATH), $(SOURCE_PRINTF:.c=.o))
OBJ_GNL =			$(addprefix $(OBJ_GNL_PATH), $(SOURCE_GNL:.c=.o))
OBJ_OWN =			$(addprefix $(OBJ_OWN_PATH), $(SOURCE_OWN:.c=.o))

OBJ = 				$(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL) $(OBJ_OWN)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@ mkdir -p $(OBJ_PATH)
	@ $(AR) $(NAME) $(OBJ)

$(OBJ_LIBFT_PATH)%.o: $(SOURCE_LIBFT_PATH)%.c
	@ mkdir -p $(OBJ_LIBFT_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PRINTF_PATH)%.o: $(SOURCE_PRINTF_PATH)%.c
	@ mkdir -p $(OBJ_PRINTF_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_GNL_PATH)%.o: $(SOURCE_GNL_PATH)%.c
	@ mkdir -p $(OBJ_GNL_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_OWN_PATH)%.o: $(SOURCE_OWN_PATH)%.c
	@ mkdir -p $(OBJ_OWN_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJ_PATH)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
