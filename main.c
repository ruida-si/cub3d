/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:18:42 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/17 19:22:23 by ruida-si         ###   ########.fr       */
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
	char	*paths[4] = {
		"images/n.xpm",
		"images/s.xpm",
		"images/e.xpm",
		"images/w.xpm"
	};
	int		i;

	i = 0;
	while (i < 4)
	{
		cub->tex[i].img = mlx_xpm_file_to_image(cub->mlx, paths[i],
			&cub->tex[i].width, &cub->tex[i].height);
		if (!cub->tex[i].img)
		{
			exit(1);
		}
		cub->tex[i].pix = (int *)mlx_get_data_addr(cub->tex[i].img,
			&cub->tex[i].bpp, &cub->tex[i].size_line, &cub->tex[i].endian);
		i++;
	}
}

