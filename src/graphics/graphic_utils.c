/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:58:33 by gribeiro          #+#    #+#             */
/*   Updated: 2025/06/27 18:34:29 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_textures(t_cub *cub);
double	deg_to_rad(double degree);

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	load_textures(t_cub *cub)
{
	char	*paths[4];
	int		i;

	paths[TEX_N] = cub->map.no;
	paths[TEX_S] = cub->map.so;
	paths[TEX_E] = cub->map.ea;
	paths[TEX_W] = cub->map.we;
	i = 0;
	while (i < 4)
	{
		cub->tex[i].img = mlx_xpm_file_to_image(cub->mlx, paths[i], \
		&cub->tex[i].width, &cub->tex[i].height);
		if (!cub->tex[i].img)
		{
			write(2, "Error\nInvalid textures\n", 23);
			while (--i >= 0)
				mlx_destroy_image(cub->mlx, cub->tex[i].img);
			cln_basic(cub);
			exit(1);
		}
		cub->tex[i].pix = (int *)mlx_get_data_addr(cub->tex[i].img, \
		&cub->tex[i].bpp, &cub->tex[i].size_line, &cub->tex[i].endian);
		i++;
	}
}

double	deg_to_rad(double degree)
{
	double	rad;

	rad = degree * (M_PI / 180);
	return (rad);
}
