/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:00:22 by bertrmar          #+#    #+#             */
/*   Updated: 2026/09/01 15:05:35 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "algo.h"

typedef struct s_cub		t_cub;
typedef struct s_data		t_data;
typedef struct s_mlx		t_mlx;
typedef struct s_v			t_v;
typedef struct s_cam		t_cam;
typedef struct s_flag		t_flag;
typedef struct s_draw		t_draw;
typedef struct s_keyhook	t_keyhook;
typedef struct s_mini		t_mini;

typedef struct s_xpm
{
	void	*img;
	void	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		linelen;
}			t_xpm;

enum	e_type
{
	NORD = 1,
	SOUTH,
	EAST,
	WEST,
};

struct	s_cub
{
	t_data		*data;
	t_mlx		*mlx;
	t_cam		*cam;
	t_v			*v;
	t_flag		*flag;
	t_draw		*draw;
	t_keyhook	*key;
	t_mini		*mini;
};

struct	s_mlx
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
	int		floor[3];
	int		celing[3];
	t_xpm	xpm[4];
	void	*t_img;
	void	*t_addr;
	int		t_bpp;
	int		t_linelen;
	int		t_endian;
};

struct	s_data
{
	struct timeval	fps;
	double			tile;
	int				fps_frame;
	int				fps_value;
	int				dir_player;
	char			**file;
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*floor;
	char			*ceiling;
	int				start;
};

struct	s_keyhook
{
	int		left;
	int		up;
	int		right;
	int		down;
	int		left_rot;
	int		right_rot;
	int		mini_map;
	int		vue;
	int		fps;
	int		sprint;
	int		esc;
};

struct	s_mini
{
	int		floor;
	int		wall;
	int		perso;
	int		fov;
	int		empty;
	int		border;
	int		pix[2];
};

/*=================== parsing ===================*/
/*.............. recup data ..............*/
int		alloc_struct(t_cub *cub3d);
int		recup_data(t_cub *cub, char *arg);
int		dispatch(t_cub *cub3d, t_data *data, int i);
int		verif_start_map(t_cub *cub3d, t_data *data, char **file, int *i);
int		search_kind_str(t_cub *cub3d, t_data *data, char **file, int *i);
int		search_len_map(t_cub *cub3d, char **file, int *len, int *i);
int		recup_floor_ceiling(t_cub *cub3d, char **data, char *file, int *arg);
int		delete_useless_space(t_cub *cub3d, int len, int i);
void	pos_player_len_map(t_cub *cub3d, t_v *v);

/*.............. keyboard ..............*/
void	hook_mlx(t_cub *cub3d);

/*.............. verif_data ..............*/
int		verif_wall(t_cub *cub3d);
int		verif_color(t_cub *cub3d, char *val, int *arg);
int		verif_map(t_cub *cub3d, char **map);
int		verif_map_no_split(t_cub *cub3d, char **map, int i, int j);

/*=================== mini_map ===================*/
void	print_floor_ceiling(t_cub *cub3d, t_draw *draw);
void	mini_map(t_cub *cub3d, int **map, int handle);
void	fov_mini_map(t_cub *cub3d, double pos_x, double pos_y, double tile);
void	recup_tile(t_cub *cub3d, int w, int h, int i);
void	draw_perso(t_cub *cub3d, double tile);
void	draw_square(t_cub *cub3d, int x, int y, int color);
void	enlarge_map(t_cub *cub3d, int **map);

/*=================== fps ===================*/
void	update_fps(t_cub *cub3d);
void	display_fps(t_cub *cub3d);

/*=================== free ===================*/
void	free_struct(t_cub *cub3d);
int		exit_game(t_cub *cub3d);

/*=================== error ===================*/
int		error(t_cub *cub3d, char *str, char *message);
int		error_sys(t_cub *cub3d, char *av);
int		error_line(t_cub *cub3d, int i);

#endif