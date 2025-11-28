/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:08:33 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/26 11:29:25 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algo.h"

static void	realign_step(t_cub *c)
{
	c->v->mapx = (int)c->v->posx;
	c->v->mapy = (int)c->v->posy;
	if (c->cam->raydirx < 0)
	{
		c->cam->stepx = -1;
		c->cam->sidedistx = ((c->v->posx) - c->v->mapx) * c->cam->deltadistx;
	}
	else
	{
		c->cam->stepx = 1;
		c->cam->sidedistx = (c->v->mapx + 1 - c->v->posx) * c->cam->deltadistx;
	}
	if (c->cam->raydiry < 0)
	{
		c->cam->stepy = -1;
		c->cam->sidedisty = (c->v->posy - c->v->mapy) * c->cam->deltadisty;
	}
	else
	{
		c->cam->stepy = 1;
		c->cam->sidedisty = (c->v->mapy + 1 - c->v->posy) * c->cam->deltadisty;
	}
}

static void	vector_check_next(t_cub *c)
{
	while (c->flag->hit == 0)
	{
		if (c->cam->sidedistx < c->cam->sidedisty)
		{
			c->cam->sidedistx += c->cam->deltadistx;
			c->v->mapx += c->cam->stepx;
			c->flag->side = 0;
		}
		else
		{
			c->cam->sidedisty += c->cam->deltadisty;
			c->v->mapy += c->cam->stepy;
			c->flag->side = 1;
		}
		if (c->v->map[c->v->mapx][c->v->mapy] == 1)
			c->flag->hit = 1;
	}
}

static void	first_value(t_cub *c, int i, double w)
{
	c->draw->x = i;
	c->cam->camx = ((2 * i) / (double)(w - 1) - 1);
	c->cam->raydirx = c->v->dirx + c->v->planex * c->cam->camx;
	c->cam->raydiry = c->v->diry + c->v->planey * c->cam->camx;
	c->cam->deltadistx = fabs(1 / c->cam->raydirx);
	c->cam->deltadisty = fabs(1 / c->cam->raydiry);
	c->flag->hit = 0;
}

static void	to_wall(t_cub *c, int i, double w)
{
	while (++i < w)
	{
		first_value(c, i, w);
		realign_step(c);
		vector_check_next(c);
		if (c->flag->side == 0)
			c->cam->pwalldist = c->cam->sidedistx - c->cam->deltadistx;
		else
			c->cam->pwalldist = c->cam->sidedisty - c->cam->deltadisty;
		c->cam->line_s = (int)(c->v->size_y / c->cam->pwalldist);
		c->draw->start = -c->cam->line_s / 2 + c->v->size_y / 2;
		if (c->draw->start < 0)
			c->draw->start = 0;
		c->draw->end = c->cam->line_s / 2 + c->v->size_y / 2;
		if (c->draw->end >= c->v->size_y)
			c->draw->end = c->v->size_y - 1;
		do_color(c);
		do_wall(c);
		new_drawing_line(c, c->draw->start, c->draw->end);
	}
}

int	core_loop(t_cub	*c)
{
	update_fps(c);
	print_floor_ceiling(c, c->draw);
	to_wall(c, -1, c->v->size_x);
	mini_map(c, c->v->map, c->key->mini_map);
	mlx_put_image_to_window(c->mlx->mlx, c->mlx->window, c->mlx->img, 0, 0);
	if (c->key->fps)
		display_fps(c);
	return (0);
}
