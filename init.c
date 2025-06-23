/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:53:31 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/23 16:56:12 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

int			key_press(int keycode, t_cub *cub);
int			key_release(int keycode, t_cub *cub);
static void	init_player(t_player *player, t_cub *cub);
static int	close_event(void *param);

void	init_display(t_cub *cub)
{
	init_player(&cub->player, cub);
	cub->mlx = mlx_init();
	mlx_get_screen_size(cub->mlx, &cub->max_width, &cub->max_height);
	cub->max_height -= 80;
	cub->win = mlx_new_window(cub->mlx, cub->max_width, cub->max_height, "cub3D");
	load_textures(cub);
	ft_memset(&cub->keys, 0, sizeof(t_keys));
	mlx_hook(cub->win, 2, 1L<<0, key_press, cub);
	mlx_hook(cub->win, 3, 1L<<1, key_release, cub);	
	mlx_hook(cub->win, 17, 0, close_event, cub);
	mlx_loop_hook(cub->mlx, game_loop, cub);
	mlx_loop(cub->mlx);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == XK_w)
		cub->keys.w = 1;
	else if (keycode == XK_a)
		cub->keys.a = 1;
	else if (keycode == XK_s)
		cub->keys.s = 1;
	else if (keycode == XK_d)
		cub->keys.d = 1;
	else if (keycode == XK_Left)
		cub->keys.left = 1;
	else if (keycode == XK_Right)
		cub->keys.right = 1;
	else if (keycode == XK_Escape)
		exit(1);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == XK_w)
		cub->keys.w = 0;
	else if (keycode == XK_a)
		cub->keys.a = 0;
	else if (keycode == XK_s)
		cub->keys.s = 0;
	else if (keycode == XK_d)
		cub->keys.d = 0;
	else if (keycode == XK_Left)
		cub->keys.left = 0;
	else if (keycode == XK_Right)
		cub->keys.right = 0;
	return (0);
}

static void	init_player(t_player *player, t_cub *cub)
{
	cub->img = NULL;
	player->pos_x = 1.5;
	player->pos_y = 1.5;
	player->angle = 180;
}

static int	close_event(void *param)
{
	(void)param;
	exit(1);
	return (0);
}
