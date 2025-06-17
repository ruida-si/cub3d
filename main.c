/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:18:42 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/17 15:30:51 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "cub3d.h"

static void	load_images(t_cub *cub);

int map[5][5] =
{
	{1, 1, 1, 1, 1},
	{1, 0, 1, 1, 1},
	{1, 0, 0, 0, 1},
	{1, 1, 0, 1, 1},
	{1, 1, 1, 1, 1}
};

int	main(void)
{
	t_cub	cub;

	load_images(&cub);
//	init_display(&cub);
	return (0);
}

static void	load_images(t_cub *cub)
{	
	cub->tex.n_img = mlx_xpm_file_to_image(cub->mlx, "images/n.xpm",
		&cub->tex.width, &cub->tex.height);
	cub->tex.n_pix = (int *)mlx_get_data_addr(cub->tex.n_img, 
		&cub->bpp, &cub->size_line, &cub->endian);
	cub->tex.s_img = mlx_xpm_file_to_image(cub->mlx, "images/s.xpm",
		&cub->tex.width, &cub->tex.height);
	cub->tex.s_pix = (int *)mlx_get_data_addr(cub->tex.s_img,
		&cub->bpp, &cub->size_line, &cub->endian);
	cub->tex.e_img = mlx_xpm_file_to_image(cub->mlx, "images/e.xpm",
		&cub->tex.width, &cub->tex.height);
	cub->tex.e_pix = (int *)mlx_get_data_addr(cub->tex.e_img,
		&cub->bpp, &cub->size_line, &cub->endian);
	cub->tex.w_img = mlx_xpm_file_to_image(cub->mlx, "images/w.xpm",
		&cub->tex.width, &cub->tex.height);
	cub->tex.w_pix = (int *)mlx_get_data_addr(cub->tex.w_img,
		&cub->bpp, &cub->size_line, &cub->endian);
}
