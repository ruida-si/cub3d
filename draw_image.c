/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:35:24 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/21 17:45:54 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

static void	print_line(t_cub *cub, t_ray *ray, int start, int end);
static int	pick_texture(t_ray *ray);

void	ft_draw_image(t_ray *ray, t_cub *cub, t_player *player)
{
	double	proj_plane;
	int		line_height;
	int		start;
	int		end;

	ray->wall_dist *= cos(deg_to_rad(ray->angle - player->angle));
	proj_plane = cub->max_height / 2.0 / tan(deg_to_rad(FOV / 2));
	line_height = (int)(1.0 / ray->wall_dist * proj_plane * 0.5);
	start = cub->max_height / 2 - line_height / 2;
	if (start < 0)
		start = 0;
	end = cub->max_height / 2 + line_height / 2;
	if (end > cub->max_height -1)
		end = cub->max_height -1;
	print_line(cub, ray, start, end);
}

static void	print_line(t_cub *cub, t_ray *ray, int start, int end)
{
	int	y;
	int	line_height;
	int	tex_x;
	int	tex_y;
	int	color;
	int	tex_id;

	tex_id = pick_texture(ray);
	tex_x = (int)(ray->wall_x * (cub->tex[tex_id].width - 1));
	if (tex_id == TEX_E || tex_id == TEX_W)
		printf("wall x: %f\n", ray->wall_x);
	y = start;
	line_height = end - start + 1;
	while (y <= end)
	{
		tex_y = (int)((double)(y - start) / line_height * cub->tex[tex_id].height);
		color = cub->tex[tex_id].pix[tex_y * cub->tex[tex_id].width + tex_x];
		cub->img_data[y * cub->max_width + ray->x] = color;
		y++;
	}
}

static int	pick_texture(t_ray *ray)
{
	int	tex_id;

	if (ray->side == X)
	{
		if (ray->raydir_x < 0)
			tex_id = TEX_W;
		else
			tex_id = TEX_E;
	}
	else
	{
		if (ray->raydir_y < 0)
			tex_id = TEX_S;
		else
			tex_id = TEX_N;
	}
	return (tex_id);
}
