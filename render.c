/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:35:24 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/14 17:51:35 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

void	ft_draw_image(t_ray *ray, t_cub *cub, t_player *player)
{
	double	proj_plane;
	int		line_height;
	int		start;
	int		end;

	ray->wall_dist *= cos(deg_to_rad(ray->angle - player->angle));
	proj_plane = cub->max_height / 2.0 / tan(deg_to_rad(FOV / 2));
	line_height = (int)(1.0 / ray->wall_dist * proj_plane * 0.5);
	printf("line height: %i ", line_height);
	start = cub->max_height / 2 - line_height / 2;
	if (start < 0)
		start = 0;
	end = cub->max_height / 2 + line_height / 2;
	if (end > cub->max_height -1)
		end = cub->max_height -1;
	while (start <= end)
	{
		cub->img_data[start * cub->max_width + ray->x] = 0x0000FF;
		start++;
	}
}
