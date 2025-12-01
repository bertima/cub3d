/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enlarge_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:56:01 by bertrmar          #+#    #+#             */
/*   Updated: 2025/12/01 11:44:51 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	enlarge_map(t_cub *cub3d, int **map)
{
	int	x;
	int	y;
	int	start;

	start = cub3d->data->start;
	recup_tile(cub3d, cub3d->v->w, cub3d->v->h, 1);
	y = 0;
	while (y < cub3d->v->h)
	{
		x = start;
		while (x < cub3d->v->w)
		{
			if (map[y][x] == 1)
				draw_square(cub3d, x - start, y, cub3d->mini->wall);
			else if (map[y][x] == 0)
				draw_square(cub3d, x - start, y, cub3d->mini->floor);
			else
				draw_square(cub3d, x - start, y, cub3d->mini->empty);
			x++;
		}
		y++;
	}
	draw_perso(cub3d, cub3d->data->tile);
}
