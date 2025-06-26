/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:11:05 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/26 14:58:55 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

static int	check_moves(t_cub *cub);
static void	check_moves2(t_cub *cub, t_player *player, double x, double y);
static void	check_wall_collision(t_player *player, double new_x, double new_y);
static void	fill_image(int *data, t_cub *cub);

int	game_loop(t_cub * cub)
{
	if (cub->img)
		mlx_destroy_image(cub->mlx, cub->img);
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img_data = (int *)mlx_get_data_addr(cub->img, &cub->bpp, &cub->size_line, &cub->endian);
	check_moves(cub);
	fill_image(cub->img_data, cub);
	raycast(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

static int	check_moves(t_cub *cub)
{
	t_player *player;

	player = &cub->player;
	if (cub->keys.left)
		player->angle = (int)(player->angle + 2) % 360;
	if (cub->keys.right)
		player->angle = (int)(player->angle - 2 + 360) % 360;
	check_moves2(cub, player, -1, -1);
	return (0);
}

static void	check_moves2(t_cub *cub, t_player *player, double x, double y)
{
	if (cub->keys.w)
	{
		x = player->pos_x + cos(deg_to_rad(player->angle)) * 0.05;
		y = player->pos_y - sin(deg_to_rad(player->angle)) * 0.05;
	}
	if (cub->keys.s)
	{
		x = player->pos_x - cos(deg_to_rad(player->angle)) * 0.05;
		y = player->pos_y + sin(deg_to_rad(player->angle)) * 0.05;
	}
	if (cub->keys.a)
	{
		x = player->pos_x + cos(deg_to_rad(player->angle + 90.0)) * 0.05;
		y = player->pos_y - sin(deg_to_rad(player->angle + 90.0)) * 0.05;
	}
	if (cub->keys.d)
	{
		x = player->pos_x + cos(deg_to_rad(player->angle - 90.0)) * 0.05;
		y = player->pos_y - sin(deg_to_rad(player->angle - 90.0)) * 0.05;
	}
	if (x != -1 && y != -1)
		check_wall_collision(player, x, y);
}

static void	check_wall_collision(t_player *player, double new_x, double new_y)
{
	int	x;
	int	y;

	x = (int)new_x;
	y = (int)new_y;
	if (map[y][x] != 1)
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

static void	fill_image(int *data, t_cub *cub)
{
	int	y;
	int	x;

	(void)cub;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				data[y * WIDTH + x] = SKY_COLOR;
			else
				data[y * WIDTH + x] = GROUND_COLOR;
			x++;
		}
		y++;
	}
}
