/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:17:48 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/27 14:49:48 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algo.h"

static int	is_wall(t_cub *c, float xi, float yi, int flag)
{
	int		x;
	int		y;
	int		dif;
	float	difi;

	x = (int)xi;
	y = (int)yi;
	if (flag == 1)
	{
		difi = xi - (float)c->v->posx;
		dif = (int)(xi + difi);
		if (c->v->map[dif][y] == 1)
			return (1);
	}
	else
	{
		difi = yi - (float)c->v->posy;
		dif = (int)(yi + difi);
		if (c->v->map[x][dif] == 1)
			return (1);
	}
	if (c->v->map[x][y] == 1)
		return (1);
	return (0);
}

void	up_move(t_cub *c)
{
	double	nx;
	double	ny;

	if (c->key->sprint == 0)
	{
		nx = c->v->posx + (c->v->dirx * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)2500));
		ny = c->v->posy + (c->v->diry * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)2500));
	}
	else
	{
		nx = c->v->posx + (c->v->dirx * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)1600));
		ny = c->v->posy + (c->v->diry * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)1600));
	}
	if (!is_wall(c, (float)nx, (float)c->v->posy, 1))
		c->v->posx = nx;
	if (!is_wall(c, (float)c->v->posx, (float)ny, 2))
		c->v->posy = ny;
}

void	down_move(t_cub *c)
{
	double	nx;
	double	ny;

	if (c->key->sprint == 0)
	{
		nx = c->v->posx - (c->v->dirx * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)2500));
		ny = c->v->posy - (c->v->diry * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)2500));
	}
	else
	{
		nx = c->v->posx - (c->v->dirx * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)1600));
		ny = c->v->posy - (c->v->diry * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)1600));
	}
	if (!is_wall(c, (float)nx, (float)c->v->posy, 1))
		c->v->posx = nx;
	if (!is_wall(c, (float)c->v->posx, (float)ny, 2))
		c->v->posy = ny;
}

void	left_move(t_cub *c)
{
	double	nx;
	double	ny;

	if (c->key->sprint == 0)
	{
		nx = c->v->posx - (c->v->diry * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)2500));
		ny = c->v->posy + (c->v->dirx * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)2500));
	}
	else
	{
		nx = c->v->posx - (c->v->diry * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)1600));
		ny = c->v->posy + (c->v->dirx * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)1600));
	}
	if (!is_wall(c, (float)nx, (float)c->v->posy, 1))
		c->v->posx = nx;
	if (!is_wall(c, (float)c->v->posx, (float)ny, 2))
		c->v->posy = ny;
}

void	right_move(t_cub *c)
{
	double	nx;
	double	ny;

	if (c->key->sprint == 0)
	{
		nx = c->v->posx + (c->v->diry * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)2500));
		ny = c->v->posy - (c->v->dirx * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)2500));
	}
	else
	{
		nx = c->v->posx + (c->v->diry * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)1600));
		ny = c->v->posy - (c->v->dirx * ((double)c->v->size / (double)5000)
				* ((double)c->v->size / (double)1600));
	}
	if (!is_wall(c, (float)nx, (float)c->v->posy, 1))
		c->v->posx = nx;
	if (!is_wall(c, (float)c->v->posx, (float)ny, 2))
		c->v->posy = ny;
}
