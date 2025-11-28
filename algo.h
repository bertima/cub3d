/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:25:46 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/28 14:13:47 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "cub3d.h"
# include <sys/time.h>
# include <math.h>

typedef struct s_cub		t_cub;
typedef struct s_data		t_data;
typedef struct s_mlx		t_mlx;
typedef struct s_v			t_v;
typedef struct s_cam		t_cam;
typedef struct s_flag		t_flag;
typedef struct s_draw		t_draw;

/* ~~~~~~~~~~~~~~~~~~~~~~~~ Structure ~~~~~~~~~~~~~~~~~~~~~~~~ */

struct s_v
{
	int		size_x; // size of screen
	int		size_y;
	int		size;
	int		h; // represent size max y;
	int		w; // represent size max x;
	int		**map;
	double	posx; //x y start position
	double	posy;
	int		mapx; // posx in int
	int		mapy;
	double	dirx; // direction 1st vector
	double	diry;
	double	planex; // raycaster version of camera plane
	double	planey;
	double	fov;
	double	wall_hit; // the exact position where the wall was hit on x axis
	int		textx; // coordinate x on the texture
	int		texty;
	double	step; // incrementation per pixel of the texture
};

struct s_cam
{
	double	camx; //x coordinate in camera space
	double	raydirx; // direction of the ray
	double	raydiry;
	double	sidedistx; // distance before the first intersection on the axis
	double	sidedisty;
	double	deltadistx; // distance between each intersection on the axis
	double	deltadisty;
	double	pwalldist; // distance cam plane to wall
	double	stepx; // recalculation of the direction of the vector
	double	stepy;
	int		line_s; // size of the line to draw
	double	textpos; // position of the texture
};

struct s_flag
{
	int		hit;
	int		side;
};

struct s_draw
{
	int		floor;
	int		ceiling;	
	int		start;
	int		end;
	int		x;
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~ PARSING ~~~~~~~~~~~~~~~~~~~~~~~~ */
void	add_vector(t_cub *c);
void	free_vmap(int **map, int size);

/* ~~~~~~~~~~~~~~~~~~~~~~~~ MATH ~~~~~~~~~~~~~~~~~~~~~~~~ */
int		core_loop(t_cub	*c);
void	do_color(t_cub *c);
void	do_wall(t_cub *c);

/* ~~~~~~~~~~~~~~~~~~~~~~~~ DRAWING ~~~~~~~~~~~~~~~~~~~~~~~~*/
void	new_drawing_line(t_cub *c, int start, int end);
void	my_mlx_pixel_put(t_cub *c, int x, int y, int color);

/* ~~~~~~~~~~~~~~~~~~~~~~~~ MOUVEMENTS ~~~~~~~~~~~~~~~~~~~~~~~~ */
void	up_move(t_cub *c);
void	down_move(t_cub *c);
void	left_move(t_cub *c);
void	right_move(t_cub *c);
void	left_rotate(t_cub *c);
void	right_rotate(t_cub *c);

#endif