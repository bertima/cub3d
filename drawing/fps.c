/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 08:53:21 by bertrmar          #+#    #+#             */
/*   Updated: 2025/11/21 14:09:30 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	update_fps(t_cub *cub3d)
{
	struct timeval	now;
	long			sec;
	long			us;
	double			gap;

	cub3d->data->fps_frame++;
	gettimeofday(&now, NULL);
	sec = now.tv_sec - cub3d->data->fps.tv_sec;
	us = now.tv_usec - cub3d->data->fps.tv_usec;
	gap = sec + us / 1000000;
	if (gap >= 1.0)
	{
		cub3d->data->fps_value = cub3d->data->fps_frame;
		cub3d->data->fps_frame = 0;
		cub3d->data->fps = now;
	}
}

static void	recup_nbr_fps(char *str, int nbr_fps)
{
	int	i;
	int	len;
	int	temp;

	len = 1;
	temp = nbr_fps;
	while (temp > 9)
	{
		temp /= 10;
		len++;
	}
	str[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		str[i] = (nbr_fps % 10) + '0';
		nbr_fps /= 10;
		len--;
		i--;
	}
}

void	display_fps(t_cub *cub3d)
{
	int		i;
	int		x;
	int		color;
	char	fps_str[24];

	i = 0;
	x = cub3d->v->size_x / 2 - 4;
	color = 0xFFFFFF;
	fps_str[0] = 'F';
	fps_str[1] = 'P';
	fps_str[2] = 'S';
	fps_str[3] = ' ';
	fps_str[4] = '=';
	fps_str[5] = ' ';
	recup_nbr_fps(&fps_str[6], cub3d->data->fps_value);
	mlx_string_put(cub3d->mlx->mlx, cub3d->mlx->window, x, 20, color, fps_str);
}
