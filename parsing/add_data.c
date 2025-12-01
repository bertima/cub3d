/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:36:58 by cowillem          #+#    #+#             */
/*   Updated: 2025/12/01 12:54:27 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algo.h"

static void	initial_dir(t_cub *c)
{
	if (c->data->dir_player == EAST)
	{
		c->v->dirx = 0;
		c->v->diry = 1;
		c->v->planex = 0.66;
	}
	else if (c->data->dir_player == WEST)
	{
		c->v->dirx = 0;
		c->v->diry = -1;
		c->v->planex = -0.66;
	}
	else if (c->data->dir_player == SOUTH)
	{
		c->v->dirx = 1;
		c->v->diry = 0;
		c->v->planey = -0.66;
	}
	else if (c->data->dir_player == NORD)
	{
		c->v->dirx = -1;
		c->v->diry = 0;
		c->v->planey = 0.66;
	}
}

static void	initial_pos(t_cub *c)
{
	int	i;
	int	j;

	i = 0;
	while (c->data->map[i])
	{
		j = 0;
		while (c->data->map[i][j])
		{
			if (c->data->map[i][j] == 'N' || c->data->map[i][j] == 'S'
				|| c->data->map[i][j] == 'E' || c->data->map[i][j] == 'W')
			{
				c->v->posx = (double)i + 0.5;
				c->v->posy = (double)j + 0.5;
				c->data->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	fill_map(int i, int *j, int ***i_map, char **map)
{
	int	a;

	a = -1;
	if (map[i][(*j)] == '0' || map[i][(*j)] == '1')
		(*i_map)[i][(*j)] = map[i][(*j)] - 48;
	else if (map[i][(*j)] == 9)
		while (++a < 4)
			(*i_map)[i][(*j)++] = 9;
	else if (map[i][(*j)] == 32)
		(*i_map)[i][(*j)] = 9;
	else
		(*i_map)[i][(*j)] = 0;
}

static int	**map_to_int(char **map, int row, int column)
{
	int	i;
	int	j;
	int	**i_map;

	i_map = malloc(sizeof(int *) * row);
	if (!i_map)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		i_map[i] = malloc(sizeof(int) * column);
		if (!i_map[i])
		{
			free_vmap(i_map, i);
			return (NULL);
		}
		j = -1;
		while (map[i][++j])
			fill_map(i, &j, &i_map, map);
		if (map[i][j] == '\0' && j != column)
			while (j < column)
				i_map[i][j++] = 9;
	}
	return (i_map);
}

void	add_vector(t_cub *c)
{
	if (c->v->size_x > c->v->size_y)
		c->v->size = c->v->size_y;
	else
		c->v->size = c->v->size_x;
	c->v->map = map_to_int(c->data->map, c->v->h,
			c->v->w);
	c->v->planex = 0;
	c->v->planey = 0;
	initial_dir(c);
	initial_pos(c);
	first_wall(c);
}
