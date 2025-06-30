# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 18:20:53 by gribeiro          #+#    #+#              #
#    Updated: 2025/04/04 18:20:53 by gribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

# Srcs
PARSE_SRCS = $(addprefix src/parsing/, \
	parse.c \
	parse_map.c \
	fill_map.c \
	parse_utils.c \
	parse_utils2.c \
	parse_utils3.c \
)

GRAPH_SRCS = $(addprefix src/graphics/, \
	init.c \
	game_loop.c \
	raycast.c \
	draw_image.c \
	graphic_utils.c \
)

SRCS = $(addprefix src/, \
	main.c \
	memclean.c \
)

OBJS = $(SRCS) $(GRAPH_SRCS) $(PARSE_SRCS)
OBJS := $(OBJS:.c=.o)

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Libs
MLX = minilibx-linux/
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
INCLUDES = -I./libft

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C ./libft
	@make -s -C $(MLX)
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a $(MLX)libmlx.a -lXext -lX11 -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

mlx:
	@if [ ! -d "$(MLX)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi

test: all
	./$(NAME) maps/map02.cub

clean:
	@make clean -C ./libft
	@make clean -s -C $(MLX)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C ./libft
	rm -f $(NAME)
	@if [ -d "$(MLX)" ]; then \
		rm -rf $(MLX); \
	fi

re: fclean all

valgrind: all
	@valgrind --show-below-main=no --leak-check=full --show-leak-kinds=all \
	--track-origins=yes -s -q ./cub3D maps/map02.cub

.PHONY: all clean fclean re
