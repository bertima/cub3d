/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:17:07 by bertrmar          #+#    #+#             */
/*   Updated: 2026/09/01 15:07:15 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	recup_tile_enlarge(t_cub *cub3d, int w, int h)
{
	int	mini_map_x;
	int	mini_map_y;

	mini_map_x = cub3d->v->size_y / w / 1.2;
	mini_map_y = cub3d->v->size_x / h / 1.2;
	if (mini_map_x < mini_map_y)
		cub3d->data->tile = mini_map_x;
	else
		cub3d->data->tile = mini_map_y;
}

void	recup_tile_mini_map(t_cub *cub3d, int w, int h, double *mini_map_x_y)
{
	if (w < 7 && h < 7)
	{
		mini_map_x_y[0] = cub3d->v->size_y / w / 8;
		mini_map_x_y[1] = cub3d->v->size_x / h / 8;
	}
	else if (w < 15 && h < 15)
	{
		mini_map_x_y[0] = cub3d->v->size_y / w / 5;
		mini_map_x_y[1] = cub3d->v->size_x / h / 5;
	}
	else if (w < 30 && h < 30)
	{
		mini_map_x_y[0] = cub3d->v->size_y / w / 4;
		mini_map_x_y[1] = cub3d->v->size_x / h / 4;
	}
	else
	{
		mini_map_x_y[0] = cub3d->v->size_y / w / 3;
		mini_map_x_y[1] = cub3d->v->size_x / h / 3;
	}
	if (mini_map_x_y[0] < mini_map_x_y[1])
		cub3d->data->tile = mini_map_x_y[0];
	else
		cub3d->data->tile = mini_map_x_y[1];
}

void	recup_tile(t_cub *cub3d, int w, int h, int i)
{
	double	mini_map_x_y[2];

	if (i == 0)
		recup_tile_mini_map(cub3d, w, h, mini_map_x_y);
	else
		recup_tile_enlarge(cub3d, w, h);
}
