/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:21:22 by bertrmar          #+#    #+#             */
/*   Updated: 2025/11/19 10:26:44 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_floor_ceiling(t_cub *cub3d, t_draw *draw)
{
	int	mid_map_h;
	int	i;
	int	j;

	i = 0;
	mid_map_h = cub3d->v->size_y * 0.5;
	while (i < cub3d->v->size_y)
	{
		j = 0;
		while (j < cub3d->v->size_x)
		{
			if (i < mid_map_h)
				my_mlx_pixel_put(cub3d, j, i, draw->ceiling);
			else
				my_mlx_pixel_put(cub3d, j, i, draw->floor);
			j++;
		}
		i++;
	}
}
