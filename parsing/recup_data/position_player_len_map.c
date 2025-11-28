/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player_len_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:02:09 by bertrmar          #+#    #+#             */
/*   Updated: 2025/11/24 12:42:46 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	perso(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

static void	orientation_player(t_data *data, char c)
{
	if (c == 'N')
		data->dir_player = NORD;
	if (c == 'E')
		data->dir_player = EAST;
	if (c == 'W')
		data->dir_player = WEST;
	if (c == 'S')
		data->dir_player = SOUTH;
}

static void	pos_player(t_data *data, t_v *v, int i, int j)
{
	char	**map;

	map = data->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (perso(map[i][j]))
			{
				orientation_player(data, map[i][j]);
				v->posx = (double)j;
				v->posy = (double)i;
			}
			j++;
		}
		i++;
	}
}

static void	len_map(char **map, t_v *v, int i, int j)
{
	int	len_max;
	int	len;

	len_max = 0;
	while (map[i])
	{
		j = 0;
		len = 0;
		while (map[i][j])
			j++;
		len = j;
		if (len > len_max)
			len_max = len;
		i++;
	}
	v->w = len_max;
	v->h = ft_len_array(map);
}

void	pos_player_len_map(t_cub *cub3d, t_v *v)
{
	if (!cub3d->data->map)
		return ;
	pos_player(cub3d->data, v, 0, 0);
	len_map(cub3d->data->map, v, 0, 0);
}
