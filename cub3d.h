/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:02:27 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/03 16:25:24 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_cub
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_data;
	int		max_width;
	int		max_height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_cub;

typedef struct s_wall
{
	int		width;
	int		height;
	void	*img;	
}	t_wall;

void	innit_display(t_cub *cub);

#endif