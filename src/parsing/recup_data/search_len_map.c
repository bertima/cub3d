/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_len_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:23:44 by bertrmar          #+#    #+#             */
/*   Updated: 2026/09/01 15:10:31 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	perso(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

static int	len_map(char **file, int *i, int len, int j)
{
	int	k;

	k = *i;
	while (file[k] && file[k][j])
	{
		while (file[k] && file[k][j] && ft_isspace(file[k][j]) == 1)
			j++;
		if (!file[k][j])
			break ;
		if (file[k][j] == '1')
			(len)++;
		else
		{
			*i = len;
			if (file[k][j] != '0' && !perso(file[k][j]))
				return (-2);
			else
				return (-1);
		}
		(k)++;
		j = 0;
	}
	return (len);
}

int	search_len_map(t_cub *cub3d, char **file, int *len, int *i)
{
	char	*error_str;

	error_str = "Floor or character cannot be at the edge of the map";
	*len = len_map(file, i, 0, 0);
	if (*len == -1)
		return (error(cub3d, error_str, NULL), error_line(cub3d, *i));
	error_str = "Map accepted only \" \", E, O, S, N, 1, 0";
	if (*len == -2)
		return (error(cub3d, error_str, NULL), error_line(cub3d, *i));
	return (0);
}
