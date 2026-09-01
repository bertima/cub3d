/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:28:02 by bertrmar          #+#    #+#             */
/*   Updated: 2026/09/01 15:13:55 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	skip_first_space(char **map, int i, int *j)
{
	if (*j == 0)
	{
		while (ft_isspace(map[i][*j]))
			(*j)++;
	}
}

static int	search_char_after_space(char **map, int i, int j)
{
	while (ft_isspace(map[i][j]))
		j++;
	if (ft_isalnum(map[i][j]))
		return (1);
	return (0);
}

static int	verif_split(char **map, int i, int j)
{
	int	len_array;
	int	len;
	int	count;

	len = 0;
	count = 0;
	len_array = ft_len_array(map);
	while (i < len_array)
	{
		len = ft_strlen(map[i]);
		if (j < len && !ft_isspace(map[i][j]))
			count++;
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int	verif_map_no_split(t_cub *cub3d, char **map, int i, int j)
{
	char	*error_str;

	error_str = "The map must be in 1 block";
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			skip_first_space(map, i, &j);
			if (ft_isspace(map[i][j]))
			{
				if (search_char_after_space(map, i, j))
				{
					if (verif_split(map, 0, j))
						return (error(cub3d, error_str, NULL));
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
