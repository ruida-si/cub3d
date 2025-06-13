/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:02:27 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/13 13:18:05 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

extern int map[5][5];

# define PI 3.1415926535897932384
# define FOV 60.0

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

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

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	angle;
}	t_player;

typedef struct s_ray
{
	double	raydir_x;
	double	raydir_y;
	double	dist_x;
	double	dist_y;
	double	f_dist_x;
	double	f_dist_y;
	double	step_x;
	double	step_y;
	double	angle;
	double	wall_dist;
}	t_ray;

void	innit_display(t_cub *cub);
double	degree_to_rad(double degree);
void	raycast(t_cub *cub);
void	ft_draw_image(t_ray *ray, t_cub *cub);

#endif