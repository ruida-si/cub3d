# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 18:49:40 by ruida-si          #+#    #+#              #
#    Updated: 2025/06/05 17:41:58 by ruida-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c innit.c \
	raycast.c utils.c

MLX = minilibx-linux/

OBJ = $(SRC:.c=.o)

NAME = cub3d

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(MLX)
	$(CC) $(FLAGS) $(OBJ) $(MLX)libmlx.a -lXext -lX11 -lm -o $(NAME)

clean:
	rm -rf $(OBJ)
	@make clean -s -C $(MLX)

fclean: clean
	rm -rf $(NAME)

re: fclean all