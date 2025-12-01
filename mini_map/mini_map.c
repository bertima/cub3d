/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:15:54 by bertrmar          #+#    #+#             */
/*   Updated: 2025/12/01 12:59:09 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	perso_pix(t_cub *cub3d, int pos_x, int pos_y, double tile)
{
	double	rad;
	int		x;
	int		y;
	int		perso;

	perso = cub3d->mini->perso;
	rad = tile * 0.25;
	y = -rad;
	while (y <= rad)
	{
		x = -rad;
		while (x <= rad)
		{
			if (x * x + y * y <= rad * rad)
				my_mlx_pixel_put(cub3d, pos_y + y, pos_x + x, perso);
			x++;
		}
		y++;
	}
}

void	draw_perso(t_cub *cub3d, double tile)
{
	double	pos_x;
	double	pos_y;

	pos_x = ((cub3d->v->posx) * tile);
	pos_y = ((cub3d->v->posy - cub3d->data->start) * tile);
	if (cub3d->key->vue == 1)
		fov_mini_map(cub3d, pos_x, pos_y, tile);
	perso_pix(cub3d, pos_x, pos_y, tile);
}

void	draw_square(t_cub *cub3d, int x, int y, int color)
{
	int	pix_square;
	int	i;
	int	j;

	i = 0;
	pix_square = (int)cub3d->data->tile;
	while (i <= pix_square)
	{
		j = 0;
		while (j <= pix_square)
		{
			if ((x == 0 || x == cub3d->v->w - cub3d->data->start - 1)
				|| (y == 0 || y == cub3d->v->h - 1))
				my_mlx_pixel_put(cub3d, (x * pix_square) + j,
					(y * pix_square) + i, cub3d->mini->border);
			else
				my_mlx_pixel_put(cub3d, (x * pix_square) + j,
					(y * pix_square) + i, color);
			j++;
		}
		i++;
	}
}

void	print_mini(t_cub *cub3d, int **map, t_mini *mini)
{
	int	x;
	int	y;
	int	start;

	start = cub3d->data->start;
	y = 0;
	while (y < cub3d->v->h)
	{
		x = start;
		while (x < cub3d->v->w)
		{
			if (map[y][x] == 1)
				draw_square(cub3d, x - start, y, mini->wall);
			else if (map[y][x] == 0)
				draw_square(cub3d, x - start, y, mini->floor);
			else
				draw_square(cub3d, x - start, y, mini->empty);
			x++;
		}
		y++;
	}
}

void	mini_map(t_cub *cub3d, int **map, int handle)
{
	t_mini	mini;

	mini.floor = 0xb5927e;
	mini.fov = 0x000000;
	mini.perso = 0xDC0700;
	mini.wall = 0x826859;
	mini.empty = 0xcccccc;
	mini.border = 0x555555;
	cub3d->mini = &mini;
	recup_tile(cub3d, cub3d->v->w, cub3d->v->h, 0);
	if (handle == 1)
		print_mini(cub3d, map, &mini);
	else if (handle == 2)
		enlarge_map(cub3d, map);
	if (handle != 0)
		draw_perso(cub3d, cub3d->data->tile);
}
