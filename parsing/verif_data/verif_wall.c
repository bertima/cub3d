/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:26:17 by bertrmar          #+#    #+#             */
/*   Updated: 2025/11/25 13:24:28 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	verif_name_xpm(t_cub *cub3d, t_data *data, char *error_str)
{
	int	len;

	len = ft_strlen(data->ea);
	if (len < 5)
		return (error(cub3d, "mlx image EA 'file'", error_str));
	if (ft_strncmp(&data->ea[len - 4], ".xpm", 5) != 0)
		return (error(cub3d, "mlx image EA ", error_str));
	len = ft_strlen(data->no);
	if (len < 5)
		return (error(cub3d, "mlx image NO 'file'", error_str));
	if (ft_strncmp(&data->no[len - 4], ".xpm", 5) != 0)
		return (error(cub3d, "mlx image NO ", error_str));
	len = ft_strlen(data->so);
	if (len < 5)
		return (error(cub3d, "mlx image SO 'file'", error_str));
	if (ft_strncmp(&data->so[len - 4], ".xpm", 5) != 0)
		return (error(cub3d, "mlx image SO ", error_str));
	len = ft_strlen(data->we);
	if (len < 5)
		return (error(cub3d, "mlx image WE 'file'", error_str));
	if (ft_strncmp(&data->we[len - 4], ".xpm", 5) != 0)
		return (error(cub3d, "mlx image WE ", error_str));
	return (0);
}

static int	verif_file_ok(t_cub *cub3d, t_mlx *mlx, t_data *data)
{
	if (verif_name_xpm(cub3d, data, ".xpm requiert"))
		return (1);
	mlx->xpm[2].img = mlx_xpm_file_to_image(mlx->mlx, data->ea,
			&mlx->xpm[2].w, &mlx->xpm[2].h);
	if (!mlx->xpm[2].img)
		return (error(cub3d, "mlx image EA fail", NULL));
	mlx->xpm[3].img = mlx_xpm_file_to_image(mlx->mlx, data->we,
			&mlx->xpm[3].w, &mlx->xpm[3].h);
	if (!mlx->xpm[3].img)
		return (error(cub3d, "mlx image WE fail", NULL));
	mlx->xpm[0].img = mlx_xpm_file_to_image(mlx->mlx, data->no,
			&mlx->xpm[0].w, &mlx->xpm[0].h);
	if (!mlx->xpm[0].img)
		return (error(cub3d, "mlx image NO fail", NULL));
	mlx->xpm[1].img = mlx_xpm_file_to_image(mlx->mlx, data->so,
			&mlx->xpm[1].w, &mlx->xpm[1].h);
	if (!mlx->xpm[1].img)
		return (error(cub3d, "mlx image SO fail", NULL));
	return (0);
}

static int	verif_addr_ok(t_cub *cub3d, t_mlx *mlx)
{
	mlx->xpm[2].addr = mlx_get_data_addr(mlx->xpm[2].img,
			&mlx->xpm[2].bpp, &mlx->xpm[2].linelen, &mlx->xpm[2].endian);
	if (!mlx->xpm[2].addr)
		return (error(cub3d, "mlx image EA fail", NULL));
	mlx->xpm[3].addr = mlx_get_data_addr(mlx->xpm[3].img,
			&mlx->xpm[3].bpp, &mlx->xpm[3].linelen, &mlx->xpm[3].endian);
	if (!mlx->xpm[3].addr)
		return (error(cub3d, "mlx image WE fail", NULL));
	mlx->xpm[0].addr = mlx_get_data_addr(mlx->xpm[0].img,
			&mlx->xpm[0].bpp, &mlx->xpm[0].linelen, &mlx->xpm[0].endian);
	if (!mlx->xpm[0].addr)
		return (error(cub3d, "mlx image NO fail", NULL));
	mlx->xpm[1].addr = mlx_get_data_addr(mlx->xpm[1].img,
			&mlx->xpm[1].bpp, &mlx->xpm[1].linelen, &mlx->xpm[1].endian);
	if (!mlx->xpm[1].addr)
		return (error(cub3d, "mlx image SO fail", NULL));
	return (0);
}

int	verif_wall(t_cub *cub3d)
{
	if (verif_file_ok(cub3d, cub3d->mlx, cub3d->data))
		return (1);
	if (verif_addr_ok(cub3d, cub3d->mlx))
		return (1);
	return (0);
}
