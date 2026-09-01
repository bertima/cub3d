/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:07:43 by cowillem          #+#    #+#             */
/*   Updated: 2026/09/01 15:15:32 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/algo.h"

unsigned int	text_to_color(t_cub *c, int x, int y)
{
	char	*pixel;

	pixel = c->mlx->t_addr + (y * c->mlx->t_linelen + x * (c->mlx->t_bpp / 8));
	return (*(unsigned int *)pixel);
}

void	do_wall(t_cub *c)
{
	if (c->flag->side == 0)
		c->v->wall_hit = c->v->posy + c->cam->walldist * c->cam->raydiry;
	else
		c->v->wall_hit = c->v->posx + c->cam->walldist * c->cam->raydirx;
	c->v->wall_hit -= floor(c->v->wall_hit);
	c->v->textx = (int)(c->v->wall_hit * (double)(c->mlx->w));
	if ((c->flag->side == 0 && c->cam->raydirx > 0)
		|| (c->flag->side == 1 && c->cam->raydiry < 0))
		c->v->textx = c->mlx->w - c->v->textx - 1;
	c->v->step = (1.0 * (double)c->mlx->h / c->cam->line_s);
	c->cam->textpos = (c->draw->start - c->v->size_y
			/ 2 + c->cam->line_s / 2) * c->v->step;
}

static void	do_color2(t_cub *c)
{
	if (c->cam->raydiry < 0)
	{
		c->mlx->t_img = c->mlx->xpm[3].img;
		c->mlx->t_addr = c->mlx->xpm[3].addr;
		c->mlx->t_bpp = c->mlx->xpm[3].bpp;
		c->mlx->t_linelen = c->mlx->xpm[3].linelen;
		c->mlx->t_endian = c->mlx->xpm[3].endian;
		c->mlx->h = c->mlx->xpm[3].h;
		c->mlx->w = c->mlx->xpm[3].w;
	}
	else
	{
		c->mlx->t_img = c->mlx->xpm[2].img;
		c->mlx->t_addr = c->mlx->xpm[2].addr;
		c->mlx->t_bpp = c->mlx->xpm[2].bpp;
		c->mlx->t_linelen = c->mlx->xpm[2].linelen;
		c->mlx->t_endian = c->mlx->xpm[2].endian;
		c->mlx->h = c->mlx->xpm[2].h;
		c->mlx->w = c->mlx->xpm[2].w;
	}
}

void	do_color(t_cub *c)
{
	if (c->flag->side == 0)
	{
		if (c->cam->raydirx < 0)
		{
			c->mlx->t_img = c->mlx->xpm[0].img;
			c->mlx->t_addr = c->mlx->xpm[0].addr;
			c->mlx->t_bpp = c->mlx->xpm[0].bpp;
			c->mlx->t_linelen = c->mlx->xpm[0].linelen;
			c->mlx->t_endian = c->mlx->xpm[0].endian;
			c->mlx->h = c->mlx->xpm[0].h;
			c->mlx->w = c->mlx->xpm[0].w;
		}
		else
		{
			c->mlx->t_img = c->mlx->xpm[1].img;
			c->mlx->t_addr = c->mlx->xpm[1].addr;
			c->mlx->t_bpp = c->mlx->xpm[1].bpp;
			c->mlx->t_linelen = c->mlx->xpm[1].linelen;
			c->mlx->t_endian = c->mlx->xpm[1].endian;
			c->mlx->h = c->mlx->xpm[1].h;
			c->mlx->w = c->mlx->xpm[1].w;
		}
	}
	else
		do_color2(c);
}

void	new_drawing_line(t_cub *c, int start, int end)
{
	int				tmp;
	unsigned int	color;

	if (start > end)
	{
		tmp = start;
		start = end;
		end = tmp;
	}
	while (start < end)
	{
		c->v->texty = (int)c->cam->textpos % (c->mlx->h - 1);
		c->cam->textpos += c->v->step;
		color = text_to_color(c, c->v->textx, c->v->texty);
		my_mlx_pixel_put(c, c->draw->x, start, color);
		start++;
	}
}
