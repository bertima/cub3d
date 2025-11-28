/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enlarge_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:56:01 by bertrmar          #+#    #+#             */
/*   Updated: 2025/11/24 13:04:11 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	enlarge_map(t_cub *cub3d, int **map)
{
	int	x;
	int	y;

	recup_tile(cub3d, cub3d->v->w, cub3d->v->h, 1);
	y = 0;
	while (y < cub3d->v->h)
	{
		x = 0;
		while (x < cub3d->v->w)
		{
			if (map[y][x] == 1)
				draw_square(cub3d, x, y, cub3d->mini->wall);
			else if (map[y][x] == 0)
				draw_square(cub3d, x, y, cub3d->mini->floor);
			else
				draw_square(cub3d, x, y, cub3d->mini->empty);
			x++;
		}
		y++;
	}
	draw_perso(cub3d, cub3d->data->tile);
}
