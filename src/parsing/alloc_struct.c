/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:39:24 by bertrmar          #+#    #+#             */
/*   Updated: 2026/09/01 15:14:42 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	alloc_next(t_cub *cub3d)
{
	cub3d->draw = ft_calloc(1, sizeof(t_draw));
	if (!cub3d->draw)
		return (error(NULL, "Malloc fail", NULL));
	cub3d->key = ft_calloc(1, sizeof(t_keyhook));
	if (!cub3d->key)
		return (error(NULL, "Malloc fail", NULL));
	cub3d->key->mini_map = 1;
	cub3d->key->vue = 1;
	gettimeofday(&cub3d->data->fps, NULL);
	return (0);
}

int	alloc_struct(t_cub *cub3d)
{
	cub3d->data = ft_calloc(1, sizeof(t_data));
	if (!cub3d->data)
		return (error(NULL, "Malloc fail", NULL));
	cub3d->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!cub3d->mlx)
		return (error(cub3d, "Malloc fail", NULL));
	cub3d->v = ft_calloc(1, sizeof(t_v));
	if (!cub3d->v)
		return (error(cub3d, "Malloc fail", NULL));
	cub3d->mlx->mlx = mlx_init();
	if (!cub3d->mlx->mlx)
		return (error(cub3d, "mlx init error", NULL));
	cub3d->cam = ft_calloc(1, sizeof(t_cam));
	if (!cub3d->cam)
		return (error(NULL, "Malloc fail", NULL));
	cub3d->flag = ft_calloc(1, sizeof(t_flag));
	if (!cub3d->flag)
		return (error(NULL, "Malloc fail", NULL));
	if (alloc_next(cub3d))
		return (1);
	return (0);
}

void	first_wall(t_cub *c)
{
	int	i;
	int	j;
	int	current;

	i = 0;
	current = 0;
	while (i < c->v->h)
	{
		j = 0;
		while (c->v->map[i][j] != 1)
			j++;
		if (i == 0)
			current = j;
		else if (j < current)
			current = j;
		i++;
	}
	c->data->start = current;
}
