NAME = libft.a

SRC = ft_atoi.c\
      ft_bzero.c\
      ft_calloc.c\
      ft_isalnum.c\
      ft_isalpha.c\
      ft_isascii.c\
      ft_isdigit.c\
      ft_isprint.c\
      ft_itoa.c\
      ft_memchr.c\
      ft_memcmp.c\
      ft_memcpy.c\
      ft_memmove.c\
      ft_memset.c\
      ft_putchar_fd.c\
      ft_putendl_fd.c\
      ft_putnbr_fd.c\
      ft_putstr_fd.c\
      ft_split.c\
      ft_strchr.c\
      ft_strdup.c\
      ft_striteri.c\
      ft_strjoin.c\
      ft_strlcat.c\
      ft_strlcpy.c\
      ft_strlen.c\
      ft_strmapi.c\
      ft_strncmp.c\
      ft_strnstr.c\
      ft_strrchr.c\
      ft_strtrim.c\
      ft_substr.c\
      ft_tolower.c\
      ft_toupper.c\
      get_next_line.c\
      get_next_line_utils.c\
      ft_lstadd_front.c\
	ft_lstadd_back.c\
      ft_lstclear.c\
      ft_lstdelone.c\
      ft_lstiter.c\
      ft_lstlast.c\
      ft_lstnew.c\
      ft_lstmap.c\
      ft_lstsize.c\

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	ar cr $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) -c $(SRC_BONUS)
	ar cr $(NAME) $(OBJ_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norme:
	norminette -R $(SRC) $(SRC_BONUS)

.PHONY: all bonus clean fclean re norme

.SILENT:
