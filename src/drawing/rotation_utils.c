/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:05:34 by cowillem          #+#    #+#             */
/*   Updated: 2026/09/01 15:15:27 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/algo.h"

void	my_mlx_pixel_put(t_cub *c, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= c->v->size_x || y < 0 || y >= c->v->size_y)
		return ;
	dst = c->mlx->addr + (y * c->mlx->line_length + x
			*(c->mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	left_rotate(t_cub *c)
{
	double	rot;
	double	olddirx;
	double	oldplanex;

	olddirx = c->v->dirx;
	rot = ((double)c->v->size_y / (double)20000)
		* ((double)c->v->size_x / (double)1500);
	c->v->dirx = c->v->dirx * cos(rot) - c->v->diry * sin(rot);
	c->v->diry = olddirx * sin(rot) + c->v->diry * cos(rot);
	oldplanex = c->v->planex;
	c->v->planex = c->v->planex * cos(rot) - c->v->planey * sin(rot);
	c->v->planey = oldplanex * sin(rot) + c->v->planey * cos(rot);
}

void	right_rotate(t_cub *c)
{
	double	oldplanex;
	double	rot;
	double	olddirx;

	rot = (-(double)c->v->size_y / (double)20000)
		* ((double)c->v->size_x / (double)1500);
	olddirx = c->v->dirx;
	c->v->dirx = c->v->dirx * cos(rot) - c->v->diry * sin(rot);
	c->v->diry = olddirx * sin(rot) + c->v->diry * cos(rot);
	oldplanex = c->v->planex;
	c->v->planex = c->v->planex * cos(rot) - c->v->planey * sin(rot);
	c->v->planey = oldplanex * sin(rot) + c->v->planey * cos(rot);
}
