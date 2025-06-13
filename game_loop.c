/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:11:05 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/13 18:49:06 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

int	game_loop(t_cub * cub)
{
	if (cub->img)
		mlx_destroy_image(cub->mlx, cub->img);
	cub->img = mlx_new_image(cub->mlx, cub->max_width, cub->max_height);
	cub->img_data = (int *)mlx_get_data_addr(cub->img, &cub->bpp, &cub->size_line, &cub->endian);
	fill_image(cub->img_data, cub);
	raycast(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}
