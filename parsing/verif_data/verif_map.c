/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:51:03 by bertrmar          #+#    #+#             */
/*   Updated: 2025/12/08 09:41:08 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	perso(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

static int	f_c(char c)
{
	if (c == '0' || c == '1')
		return (1);
	return (0);
}

static int	verif_arg_map(t_cub *cub3d, char **map, int i, int j)
{
	char	*str;
	int		count;

	count = 0;
	str = "Map accepted only \" \", E, O, S, N, 1, 0";
	if (!map)
		return (error(cub3d, "No map no game", NULL));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!perso(map[i][j]) && !f_c(map[i][j]) && !ft_isspace(map[i][j]))
				return (error(cub3d, str, NULL), error_line(cub3d, i));
			if (perso(map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (error(cub3d, "Map must have 1 player", NULL));
	return (0);
}

static int	verif_placement(t_cub *cub3d, char **map, int i, int j)
{
	char	*error_str;

	error_str = "Floor or character cannot be at the edge of the map";
	if (i <= 0 || j <= 0 || i >= ft_len_array(map) - 1
		|| j >= (int)ft_strlen(map[i]))
		return (error(cub3d, error_str, NULL));
	if (!map[i + 1][j] || !map[i - 1][j] || !map[i][j + 1] || !map[i][j - 1]
		|| !map[i + 1][j + 1] || !map[i - 1][j + 1]
		|| !map[i - 1][j + 1] || !map[i - 1][j - 1]
		|| (!perso(map[i + 1][j]) && !f_c(map[i + 1][j]))
		|| (!perso(map[i - 1][j]) && !f_c(map[i - 1][j]))
		|| (!perso(map[i][j + 1]) && !f_c(map[i][j + 1]))
		|| (!perso(map[i][j - 1]) && !f_c(map[i][j - 1]))
		|| (!perso(map[i + 1][j + 1]) && !f_c(map[i + 1][j + 1]))
		|| (!perso(map[i - 1][j + 1]) && !f_c(map[i - 1][j + 1]))
		|| (!perso(map[i + 1][j - 1]) && !f_c(map[i + 1][j - 1]))
		|| (!perso(map[i - 1][j - 1]) && !f_c(map[i - 1][j - 1])))
		return (error(cub3d, error_str, NULL));
	return (0);
}

int	verif_map(t_cub *cub3d, char **map)
{
	int	i;
	int	j;

	i = 0;
	if (verif_arg_map(cub3d, map, 0, 0))
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (perso(map[i][j]) || map[i][j] == '0')
			{
				if (verif_placement(cub3d, map, i, j))
					return (error_line(cub3d, i));
			}
			j++;
		}
		i++;
	}
	if (verif_map_no_split(cub3d, map, 0, 0))
		return (1);
	return (0);
}
