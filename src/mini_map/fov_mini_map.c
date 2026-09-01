/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_mini_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:06:54 by bertrmar          #+#    #+#             */
/*   Updated: 2026/09/01 15:07:00 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*void	ray_trace(t_cub *cub3d, double pos_x, double pos_y, double *dir)
{
	int		map_x;
	int		map_y;
	int		color;

	color = cub3d->mini->fov;
	while (1)
	{
		pos_x += dir[0];
		pos_y += dir[1];
		map_y = (pos_y / cub3d->data->tile);
		map_x = (pos_x / cub3d->data->tile);
		if (map_x < 0 || map_y < 0
			|| map_y >= cub3d->v->w || map_x >= cub3d->v->h)
			break ;
		if (cub3d->v->map[map_x][map_y] == 1)
			break ;
		my_mlx_pixel_put(cub3d, pos_y, pos_x, color);
	}
}

void	fov_mini_map(t_cub *cub3d, double pos_x, double pos_y, int nbr_ray)
{
	double	start_angle;
	double	angle;
	double	dir[2];
	int		i;

	cub3d->v->fov = (double)66.66 * (3.14159265359 / (double)180);
	start_angle = atan2(cub3d->v->diry, cub3d->v->dirx) - (cub3d->v->fov / 2);
	i = 0;
	while (i <= nbr_ray)
	{
		angle = start_angle + (i * cub3d->v->fov) / nbr_ray;
		dir[0] = cos(angle);
		dir[1] = sin(angle);
		ray_trace(cub3d, pos_x, pos_y, dir);
		i++;
	}
}*/

static void	fov_dir_shape(t_cub *cub3d, int map_x, int map_y, double ang)
{
	double	i;
	double	j;
	double	h;
	double	l;

	l = cub3d->data->tile * 0.2;
	h = cub3d->data->tile * 0.3;
	i = 0;
	while (i <= h)
	{
		j = l * (i / h);
		while (j >= -l * (i / h))
		{
			cub3d->mini->pix[0] = (map_x - i * cos(ang) - j * sin(ang));
			cub3d->mini->pix[1] = (map_y - i * sin(ang) + j * cos(ang));
			my_mlx_pixel_put(cub3d, cub3d->mini->pix[1], cub3d->mini->pix[0],
				cub3d->mini->fov);
			j -= 0.5;
		}
		i += 0.5;
	}
}

void	fov_mini_map(t_cub *cub3d, double pos_x, double pos_y, double tile)
{
	double	map_x;
	double	map_y;
	double	gap;
	double	angle;

	angle = atan2(cub3d->v->diry, cub3d->v->dirx);
	gap = tile * 0.8;
	map_x = pos_x + cub3d->v->dirx * gap;
	map_y = pos_y + cub3d->v->diry * gap;
	fov_dir_shape(cub3d, map_x, map_y, angle);
}
