/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:53:31 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/13 18:45:36 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

void	innit_player(t_player *player, t_cub *cub);
static int	key_handler(int key, void *param);
static int	close_event(void *param);

void	innit_display(t_cub *cub)
{
	innit_player(&cub->player, cub);
	cub->mlx = mlx_init();
	mlx_get_screen_size(cub->mlx, &cub->max_width, &cub->max_height);
	cub->max_height -= 80;
	cub->win = mlx_new_window(cub->mlx, cub->max_width, cub->max_height, "cub3D");
	mlx_loop_hook(cub->mlx, game_loop, cub);
	mlx_key_hook(cub->win, key_handler, &cub);
	mlx_hook(cub->win, 17, 0, close_event, &cub);
	mlx_loop(cub->mlx);
}

void	innit_player(t_player *player, t_cub *cub)
{
	cub->img = NULL;
	player->pos_x = 3.5;
	player->pos_y = 2.5;
	player->angle = 135;
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
				data[i * cub->max_width + j] = 0xADD8E6;
			}
			else
				data[i * cub->max_width + j] = 0x8B4513;
			j++;
		}
		i++;
	}
}

static int	key_handler(int key, void *param)
{
	t_cub *cub;
	
	cub = (t_cub *)param;	
	if (key == 65307)
	{
		exit(1);
	}
	if (key == KEY_LEFT)
		cub->player.angle += 15;
	if (key == KEY_RIGHT)
		cub->player.angle -= 15;		
	return (0);
}

static int	close_event(void *param)
{
	(void)param;
	exit(1);
	return (0);
}
