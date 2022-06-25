# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/12 21:42:39 by fdarrin           #+#    #+#              #
#    Updated: 2020/09/12 21:42:47 by fdarrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = -I ./mlx
HEADER = headers/cub3d.h

SRC = srcs/cub3d.c \
        srcs/init_1.c \
        srcs/init_2.c \
        srcs/get_resolution.c \
        srcs/get_color.c \
        srcs/get_texture_path.c \
		srcs/get_map.c \
		srcs/map_make.c \
		srcs/map_check.c \
		srcs/draw_cub.c \
		srcs/draw_maze.c \
		srcs/draw_sprites.c \
		srcs/init_textures.c \
		srcs/raycasting.c \
		srcs/image_keys.c \
		srcs/make_screenshot.c \
		srcs/textures_color.c \
		srcs/utils.c

OBJ = $(SRC:.c=.o)

%.o: %.c
		$(CC) $(FLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) libft mlx
		cp ./mlx/libmlx.dylib ./
		$(CC) -Lmlx ./libft/libft.a -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

libft:
		$(MAKE) -C libft

mlx:
		$(MAKE) -C mlx

clean:
		rm -rf $(OBJ)
		$(MAKE) -C libft clean
		$(MAKE) -C mlx clean

fclean:
		rm -rf $(OBJ) $(NAME)
		rm -rf libmlx.dylib
		$(MAKE) -C mlx clean
		$(MAKE) -C libft fclean

re:		fclean all

.PHONY: clean fclean all re libft mlx
