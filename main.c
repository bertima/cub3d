/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:53:43 by cowillem          #+#    #+#             */
/*   Updated: 2025/12/05 14:48:37 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	size_window(t_cub *cub3d)
{
	char	*error_str;

	cub3d->v->size_x = 1000;
	cub3d->v->size_y = 1000;
	error_str = "Size for window is minimum width : 400 height : 400";
	if (cub3d->v->size_x < 400 || cub3d->v->size_y < 400)
		return (error(cub3d, error_str, NULL));
	error_str = "Size for window is minimum width : 3000 height : 2000";
	if (cub3d->v->size_x > 3000 || cub3d->v->size_y > 2000)
		return (error(cub3d, error_str, NULL));
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub3d;

	ft_memset(&cub3d, 0, sizeof(t_cub));
	if (ac != 2)
		return (error(NULL, "One file.cub requiert for program", NULL));
	if (alloc_struct(&cub3d))
		return (1);
	if (size_window(&cub3d))
		return (1);
	if (recup_data(&cub3d, av[1]))
		return (1);
	add_vector(&cub3d);
	cub3d.mlx->window = mlx_new_window(cub3d.mlx->mlx,
			cub3d.v->size_x, cub3d.v->size_y, "CUB3D");
	if (!cub3d.mlx->window)
		return (error(&cub3d, "Window mlx fail", NULL));
	cub3d.mlx->img = mlx_new_image(cub3d.mlx->mlx,
			cub3d.v->size_x, cub3d.v->size_y);
	cub3d.mlx->addr = mlx_get_data_addr(cub3d.mlx->img,
			&cub3d.mlx->bits_per_pixel, &cub3d.mlx->line_length,
			&cub3d.mlx->endian);
	hook_mlx(&cub3d);
	mlx_loop(cub3d.mlx->mlx);
	core_loop(&cub3d);
	free_struct(&cub3d);
}
