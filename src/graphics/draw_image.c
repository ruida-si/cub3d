/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:35:24 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/27 18:32:31 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	print_line(t_cub *cub, t_ray *ray, int start, int end);
static int	pick_texture(t_ray *ray);

void	ft_draw_image(t_ray *ray, t_cub *cub, t_player *player)
{
	double	proj_plane;
	int		line_height;
	int		start;
	int		end;

	ray->wall_dist *= cos(deg_to_rad(ray->angle - player->angle));
	proj_plane = HEIGHT / 2.0 / tan(deg_to_rad(FOV / 2));
	line_height = (int)(1.0 / ray->wall_dist * proj_plane * 0.5);
	start = HEIGHT / 2 - line_height / 2;
	end = HEIGHT / 2 + line_height / 2;
	print_line(cub, ray, start, end);
}

static void	print_line(t_cub *cub, t_ray *ray, int start, int end)
{
	int	y;
	int	line_height;
	int	color;
	int	tex_id;

	tex_id = pick_texture(ray);
	cub->tex[tex_id].tex_x = (int)(ray->wall_x * (cub->tex[tex_id].width - 1));
	y = start;
	line_height = end - start + 1;
	while (y <= end)
	{
		if (y >= 0 && y < HEIGHT)
		{
			cub->tex[tex_id].tex_y = (int)((double)(y - start) / line_height \
			* (cub->tex[tex_id].height - 1));
			color = cub->tex[tex_id].pix[cub->tex[tex_id].tex_y \
			* cub->tex[tex_id].width + cub->tex[tex_id].tex_x];
			cub->img_data[y * WIDTH + ray->x] = color;
		}
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
