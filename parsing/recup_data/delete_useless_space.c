/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_useless_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:04:44 by bertrmar          #+#    #+#             */
/*   Updated: 2025/12/08 10:11:48 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	copie_map_del_space(char **temp, char *map, int len, int i)
{
	while (i < len)
	{
		(*temp)[i] = map[i];
		i++;
	}
}

int	delete_useless_space(t_cub *cub3d, int len, int i)
{
	char	**map;
	char	**temp;

	temp = calloc(len + 1, sizeof(char *));
	if (!temp)
		return (error(cub3d, "Malloc fail", NULL));
	map = cub3d->data->map;
	while (map[i])
	{
		len = ft_strlen(map[i]) - 1;
		while (len > 0 && ft_isspace(map[i][len]))
			len--;
		len++;
		temp[i] = calloc(len + 1, sizeof(char));
		if (!temp[i])
			return (ft_free_array(temp), error(cub3d, "Malloc fail", NULL));
		copie_map_del_space(&temp[i], map[i], len, 0);
		i++;
	}
	ft_free_array(cub3d->data->map);
	cub3d->data->map = temp;
	return (0);
}
