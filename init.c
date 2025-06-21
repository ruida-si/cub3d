/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:53:31 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/21 17:27:50 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

static void	init_player(t_player *player, t_cub *cub);
static int	key_handler(int key, void *param);
static void	check_moves(t_player *player, int key, double x, double y);
static void	check_wall_collision(t_player *player, double new_x, double new_y);
static int	close_event(void *param);

void	init_display(t_cub *cub)
{
	init_player(&cub->player, cub);
	cub->mlx = mlx_init();
	mlx_get_screen_size(cub->mlx, &cub->max_width, &cub->max_height);
	cub->max_height -= 80;
	cub->win = mlx_new_window(cub->mlx, cub->max_width, cub->max_height, "cub3D");
	load_textures(cub);
	mlx_key_hook(cub->win, key_handler, cub);
	mlx_hook(cub->win, 17, 0, close_event, cub);
	mlx_loop_hook(cub->mlx, game_loop, cub);
	mlx_loop(cub->mlx);
}

static void	init_player(t_player *player, t_cub *cub)
{
	cub->img = NULL;
	player->pos_x = 1.5;
	player->pos_y = 1.5;
	player->angle = 180;
}

static int	key_handler(int key, void *param)
{
	t_cub		*cub;
	t_player	*player;
	
	cub = (t_cub *)param;
	player = &cub->player;
	if (key == XK_Escape)
		exit(1);
	if (key == XK_Left)
		player->angle = (int)(player->angle + 15) % 360;
	if (key == XK_Right)
		player->angle = (int)(player->angle - 15 + 360) % 360;
	check_moves(player, key, -1, -1);
	return (0);
}

static void	check_moves(t_player *player, int key, double x, double y)
{
	if (key == XK_w)
	{
		x = player->pos_x + cos(deg_to_rad(player->angle)) * 0.1;
		y = player->pos_y - sin(deg_to_rad(player->angle)) * 0.1;
	}
	if (key == XK_s)
	{
		x = player->pos_x - cos(deg_to_rad(player->angle)) * 0.1;
		y = player->pos_y + sin(deg_to_rad(player->angle)) * 0.1;
	}
	if (key == XK_a)
	{
		x = player->pos_x + cos(deg_to_rad(player->angle + 90.0)) * 0.1;
		y = player->pos_y - sin(deg_to_rad(player->angle + 90.0)) * 0.1;
	}
	if (key == XK_d)
	{
		x = player->pos_x + cos(deg_to_rad(player->angle - 90.0)) * 0.1;
		y = player->pos_y - sin(deg_to_rad(player->angle - 90.0)) * 0.1;
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

static int	close_event(void *param)
{
	(void)param;
	exit(1);
	return (0);
}
