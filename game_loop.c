/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:11:05 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/23 17:07:11 by ruida-si         ###   ########.fr       */
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
	cub->img = mlx_new_image(cub->mlx, cub->max_width, cub->max_height);
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
	int	i;
	int	j;

	i = 0;
	while (i < cub->max_height)
	{
		j = 0;
		while (j < cub->max_width)
		{
			if (i < cub->max_height / 2)
			{
				data[i * cub->max_width + j] = SKY_COLOR;
			}
			else
				data[i * cub->max_width + j] = GROUND_COLOR;
			j++;
		}
		i++;
	}
}
