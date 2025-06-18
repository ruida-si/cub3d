/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:46:31 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/18 18:52:55 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

double	deg_to_rad(double degree)
{
	double	rad;

	rad = degree * (M_PI / 180);
	return (rad);
}

void	load_images(t_cub *cub)
{
	char	*paths[4] = {
		"images/n.xpm",
		"images/s.xpm",
		"images/e.xpm",
		"images/w.xpm"
	};
	int	i;

	i = 0;
	while (i < 4)
	{
		cub->tex[i].img = mlx_xpm_file_to_image(cub->mlx, paths[i],
			&cub->tex[i].width, &cub->tex[i].height);
		if (!cub->tex[i].img)
		{
			printf("Could not load Texture\n");
			exit(1);
		}
		cub->tex[i].pix = (int *)mlx_get_data_addr(cub->tex[i].img,
			&cub->tex[i].bpp, &cub->tex[i].size_line, &cub->tex[i].endian);
		i++;
	}
}
