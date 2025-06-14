/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:53:31 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/14 17:53:20 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

void		init_player(t_player *player, t_cub *cub);
void		fill_image(int *data, t_cub *cub);
static int	key_handler(int key, void *param);
static int	close_event(void *param);

void	init_display(t_cub *cub)
{
	init_player(&cub->player, cub);
	cub->mlx = mlx_init();
	mlx_get_screen_size(cub->mlx, &cub->max_width, &cub->max_height);
	cub->max_height -= 80;
	cub->win = mlx_new_window(cub->mlx, cub->max_width, cub->max_height, "cub3D");
	mlx_key_hook(cub->win, key_handler, cub);
	mlx_hook(cub->win, 17, 0, close_event, cub);
	mlx_loop_hook(cub->mlx, game_loop, cub);
	mlx_loop(cub->mlx);
}

void	init_player(t_player *player, t_cub *cub)
{
	cub->img = NULL;
	player->pos_x = 2.5;
	player->pos_y = 2.5;
	player->angle = 90;
}

void	fill_image(int *data, t_cub *cub)
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
	if (key == XK_w)
	{
		player->pos_x += cos(deg_to_rad(player->angle)) * 0.1;
		player->pos_y -= sin(deg_to_rad(player->angle)) * 0.1;
	}
	if (key == XK_s)
	{
		player->pos_x -= cos(deg_to_rad(player->angle)) * 0.1;
		player->pos_y += sin(deg_to_rad(player->angle)) * 0.1;
	}
	if (key == XK_a)
	{
		player->pos_x += cos(deg_to_rad(player->angle + 90.0)) * 0.1;
		player->pos_y -= sin(deg_to_rad(player->angle + 90.0)) * 0.1;
	}
	if (key == XK_d)
	{
		player->pos_x += cos(deg_to_rad(player->angle - 90.0)) * 0.1;
		player->pos_y -= sin(deg_to_rad(player->angle - 90.0)) * 0.1;
	}
	return (0);
}

static int	close_event(void *param)
{
	(void)param;
	exit(1);
	return (0);
}
