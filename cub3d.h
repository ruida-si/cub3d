/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:02:27 by ruida-si          #+#    #+#             */
/*   Updated: 2025/06/14 16:44:59 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

extern int map[5][5];

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <X11/keysym.h>

// VARIABLES
# define FOV 60.0

// COLORS
#define SKY_COLOR 0xADD8E6
#define GROUND_COLOR 0x8B4513

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
}	t_player;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_data;
	int			max_width;
	int			max_height;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;
}	t_cub;

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
	int		x;
}	t_ray;

// INNIT
void	init_display(t_cub *cub);

// UTILS
double	degree_to_rad(double degree);

// RAYCAST
void	raycast(t_cub *cub);

// RENDERING IMAGE
void	ft_draw_image(t_ray *ray, t_cub *cub, t_player *player);
int		game_loop(t_cub * cub);
void	fill_image(int *data, t_cub *cub);

#endif