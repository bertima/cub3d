/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:25:46 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/27 14:39:30 by cowillem         ###   ########.fr       */
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
	int		size_x; // taille de l'ecran
	int		size_y;
	int		size;
	int		h; // hauteur qui represente la taille max de y;
	int		w; // largeur qui represente la taille max de x;
	int		**map;
	double	posx; //x y start position
	double	posy;
	int		mapx; // posx en int
	int		mapy;
	double	dirx; // direction vector de base
	double	diry;
	double	planex; // raycaster version of camera plane
	double	planey;
	double	fov; // (2 * atan(0.66/1.0) = 66 degree
	double	wall_hit; // a quel endroit precis le mur a ete hit sur l'axe x
	int		textx; // coordonne x de la texture
	int		texty;
	double	step; // incrementation texture par pixel
};

struct s_cam
{
	double	camx; //x coordinate in camera space
	double	raydirx; // direction du rayon
	double	raydiry;
	double	sidedistx; // distance avant premier croisement sur l'axe
	double	sidedisty;
	double	deltadistx; // distance entre chaque croisement apres le 1er sur l'axe
	double	deltadisty;
	double	pwalldist; // distance cam plane a mur
	double	stepx; // recalcul direction du vecteur
	double	stepy;
	int		line_s; // la taille de la ligne a dessiner
	double	textpos; // position de la texture
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