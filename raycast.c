/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:15:20 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/17 14:44:13 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

static void	apply_dda(t_ray *ray, t_player *player, t_cub *cub);
static void	init_ray(t_ray *ray, t_player *player, int map_x, int map_y);

void	raycast(t_cub *cub)
{
	int			x;
	t_ray		ray;
	double		deg_step;

	x = 0;
	deg_step = FOV / (cub->max_width - 1);
	while (x < cub->max_width)
	{
		ray.x = x;
		ray.angle = (cub->player.angle + (FOV / 2)) - (x * deg_step);
		ray.raydir_x = cos(deg_to_rad(ray.angle));
		ray.raydir_y = sin(deg_to_rad(ray.angle));
		ray.dist_x = fabs(1 / ray.raydir_x);
		ray.dist_y = fabs(1 / ray.raydir_y);
		apply_dda(&ray, &cub->player, cub);
		x++;
	}
}

static void	apply_dda(t_ray *ray, t_player *player, t_cub *cub)
{
	int	map_x;
	int	map_y;

	map_x = (int)player->pos_x;
	map_y = (int)player->pos_y;
	init_ray(ray, player, map_x, map_y);
	while (1)
	{
		if (ray->f_dist_x < ray->f_dist_y)
		{
			ray->f_dist_x += ray->dist_x;
			map_x += ray->step_x;
			ray->side = X;
		}
		else
		{
			ray->f_dist_y += ray->dist_y;
			map_y += ray->step_y;
			ray->side = Y;
		}
		if (map[map_y][map_x] == 1)
			break ;
	}
	if (ray->side == X)
		ray->wall_dist = ray->f_dist_x - ray->dist_x;
	else
		ray->wall_dist = ray->f_dist_y - ray->dist_y;
	printf("wall dist: %f angle: %f\n", ray->wall_dist, ray->angle);
	ft_draw_image(ray, cub, player);
}

static void	init_ray(t_ray *ray, t_player *player, int map_x, int map_y)
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

