/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:01:08 by bertrmar          #+#    #+#             */
/*   Updated: 2025/12/08 10:27:21 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	verif_map_last(t_cub *cub3d, t_data *data, char **file, int i)
{
	int	j;
	int	len;

	len = ft_len_array(data->file);
	j = 0;
	while (ft_isspace(file[i][j]))
		j++;
	if (ft_strncmp(&file[i][j], "", 1) == 0)
		return (0);
	else
		return (error(cub3d, "Map must be the last data", NULL));
	return (0);
}

static void	copie_map(char **temp, char *map, int j, int l)
{
	int	space;

	while (map[j])
	{
		if (map[j] == '\t')
		{
			space = (j + l) + (4 - ((j + l) % 4));
			while (j + l < space)
			{
				(*temp)[j + l] = ' ';
				l++;
			}
			l--;
		}
		else
			(*temp)[j + l] = map[j];
		j++;
	}
}

static int	transform_tab(t_data *data, int len_map, int i, int j)
{
	char	**temp;
	int		len;

	temp = ft_calloc(len_map + 1, sizeof(char *));
	if (!temp)
		return (1);
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '\t')
				len += 4;
			j++;
		}
		temp[i] = ft_calloc(len + 1, sizeof(char));
		if (!temp[i])
			return (1);
		copie_map(&temp[i], data->map[i], 0, 0);
		i++;
	}
	ft_free_array(data->map);
	data->map = temp;
	return (0);
}

static int	recup_map(t_cub *cub3d, t_data *data, char **file, int *i)
{
	int		k;
	int		len;

	k = 0;
	len = 0;
	if (search_len_map(cub3d, file, &len, i))
		return (1);
	data->map = ft_calloc(len + 1, sizeof(char *));
	if (!cub3d->data->map)
		return (error(cub3d, "Malloc fail", NULL));
	while (*i + k < *i + len)
	{
		data->map[k] = ft_strdup(file[*i + k]);
		if (!data->map[k])
			return (error(cub3d, "Malloc fail", NULL));
		k++;
	}
	if (delete_useless_space(cub3d, len, 0))
		return (1);
	if (transform_tab(data, len, 0, 0))
		return (error(cub3d, "Malloc fail", NULL));
	*i += len - 1;
	return (0);
}

int	verif_start_map(t_cub *cub3d, t_data *data, char **file, int *i)
{
	int	j;
	int	len;

	len = ft_len_array(data->file);
	if (!data->map)
	{
		if (recup_map(cub3d, data, file, i))
			return (2);
		if (verif_map(cub3d, cub3d->data->map))
			return (2);
		j = *i + 1;
		while (j < len)
		{
			if (verif_map_last(cub3d, data, file, j))
				return (1);
			j++;
		}
	}
	else
		return (error(cub3d, "The map must be in 1 block", NULL));
	return (0);
}
