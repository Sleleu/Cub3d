# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 19:08:41 by sleleu            #+#    #+#              #
#    Updated: 2022/11/24 16:38:34 by sleleu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	src/main.c \
		src/parse.c \
		src/wall_error.c \

OBJS = $(SRC:.c=.o)

CC = gcc

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -g3 -O3 -c $< -o $@

all: $(NAME)

$(NAME): ./mlx_linux/libmlx.a $(OBJ)
	make -sC libft
	$(CC) $(SRC) $(INC) $(OBJ) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

mlx_linux/libmlx.a:
	make -C mlx_linux

clean:
	rm -rfv $(OBJS)
	make clean -C mlx_linux
	make clean -C libft

fclean: clean
	rm -rfv $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re