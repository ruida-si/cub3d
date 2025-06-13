/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:15:20 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/13 13:50:41 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

void	apply_dda(t_ray *ray, t_player *player, t_cub *cub);
void	innit_player(t_player *player);
void	innit_ray(t_ray *ray, t_player *player, int map_x, int map_y);

void	raycast(t_cub *cub)
{
	int			x;
	t_player	player;
	t_ray		ray;
	double		deg_step;

	cub->max_width = 1920;
	x = 0;
	innit_player(&player);
	deg_step = FOV / (cub->max_width - 1);
	while (x < cub->max_width)
	{
		ray.angle = (player.angle + (FOV / 2)) - (x * deg_step);
		ray.raydir_x = cos(degree_to_rad(ray.angle));
		ray.raydir_y = sin(degree_to_rad(ray.angle));
		ray.dist_x = fabs(1 / ray.raydir_x);
		ray.dist_y = fabs(1 / ray.raydir_y);
		apply_dda(&ray, &player, cub);
		x++;
	}
}

void	apply_dda(t_ray *ray, t_player *player, t_cub *cub)
{
	int	map_x;
	int	map_y;
	int	side;
	
	(void)cub;
	map_x = (int)player->pos_x;
	map_y = (int)player->pos_y;
	innit_ray(ray, player, map_x, map_y);
	while (1)
	{
		if (ray->f_dist_x < ray->f_dist_y)
		{
			ray->f_dist_x += ray->dist_x;
			map_x += ray->step_x;
			side = 0;
		}
		else
		{
			ray->f_dist_y += ray->dist_y;
			map_y += ray->step_y;
			side = 1;
		}
		if (map[map_y][map_x] == 1)
			break ;
	}
	if (side == 0)
	{
		ray->f_dist_x -= ray->dist_x;
		ray->wall_dist = ray->f_dist_x;
	}
	else
	{
		ray->f_dist_y -= ray->dist_y;
		ray->wall_dist = ray->f_dist_y;
	}
	printf("wall dist: %f angle: %f\n", ray->wall_dist, ray->angle);
//	ft_draw_image(ray, cub);
}

void	innit_ray(t_ray *ray, t_player *player, int map_x, int map_y)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->f_dist_x = (player->pos_x - map_x) * ray->dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->f_dist_x = (map_x + 1 - player->pos_x) * ray->dist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = 1;
		ray->f_dist_y = (map_y + 1 - player->pos_y) * ray->dist_y;
	}
	else
	{
		ray->step_y = -1;
		ray->f_dist_y = (player->pos_y - map_y) * ray->dist_y;
	}
}

void	innit_player(t_player *player)
{
	player->pos_x = 2.5;
	player->pos_y = 2.5;
	player->dir_x = 0.0;
	player->dir_y = 1.0;
	player->angle = 30;
}
