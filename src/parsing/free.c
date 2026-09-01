/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:45:31 by cowillem          #+#    #+#             */
/*   Updated: 2026/09/01 15:14:50 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	free_mlx(t_mlx *mlx)
{
	if (mlx->mlx)
	{
		if (mlx->xpm[0].img)
			mlx_destroy_image(mlx->mlx, mlx->xpm[0].img);
		if (mlx->xpm[1].img)
			mlx_destroy_image(mlx->mlx, mlx->xpm[1].img);
		if (mlx->xpm[2].img)
			mlx_destroy_image(mlx->mlx, mlx->xpm[2].img);
		if (mlx->xpm[3].img)
			mlx_destroy_image(mlx->mlx, mlx->xpm[3].img);
		if (mlx->img)
			mlx_destroy_image(mlx->mlx, mlx->img);
		if (mlx->window)
		{
			mlx_clear_window(mlx->mlx, mlx->window);
			mlx_destroy_window(mlx->mlx, mlx->window);
		}
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

static void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->file)
		ft_free_array(data->file);
	if (data->map)
		ft_free_array(data->map);
	if (data->ea)
		free(data->ea);
	if (data->we)
		free(data->we);
	if (data->so)
		free(data->so);
	if (data->no)
		free(data->no);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
}

void	free_vmap(int **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

static void	free_key_mlx(t_cub *cub3d)
{
	if (cub3d->key)
		free(cub3d->key);
	if (cub3d->mlx)
	{
		free_mlx(cub3d->mlx);
		free(cub3d->mlx);
		cub3d->mlx = NULL;
	}
}

void	free_struct(t_cub *cub3d)
{
	if (!cub3d)
		return ;
	if (cub3d->v)
	{
		if (cub3d->v->map)
			free_vmap(cub3d->v->map, cub3d->v->h);
		free(cub3d->v);
	}
	if (cub3d->data)
	{
		free_data(cub3d->data);
		free(cub3d->data);
	}
	if (cub3d->cam)
		free(cub3d->cam);
	if (cub3d->flag)
		free(cub3d->flag);
	if (cub3d->draw)
		free(cub3d->draw);
	free_key_mlx(cub3d);
}
