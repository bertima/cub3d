/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_kind_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:56:12 by bertrmar          #+#    #+#             */
/*   Updated: 2026/09/01 15:10:28 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	verif_first_line(char *file, int i)
{
	while (file[i] && (file[i] == '0' || file[i] == '1'
			|| ft_isspace(file[i])
			|| file[i] == 'N' || file[i] == 'E'
			|| file[i] == 'W' || file[i] == 'S'))
		i++;
	if (file[i] == '\0')
		return (1);
	return (0);
}

static int	verif_number_arg(t_cub *cub3d, char *file, int len)
{
	while (file[len])
	{
		if (!ft_isspace(file[len]))
			return (error(cub3d, "Only 1 data requiert", NULL));
		len++;
	}
	return (0);
}

static int	search_str(t_cub *cub3d, char **data, char *file, int count)
{
	int	len;
	int	j;

	j = 0;
	len = 0;
	if (*data)
		return (error(cub3d, *data, ": already init"));
	if (!file[j])
		return (error(cub3d, "Data is empty", NULL));
	while (file[j] && ft_isspace(file[j]) == 1)
	{
		count++;
		j++;
	}
	if (count == 0)
		return (error(cub3d, "Space is requiert after data", NULL));
	while (file[j + len] && !ft_isspace(file[j + len]))
		len++;
	if (verif_number_arg(cub3d, file, len + j))
		return (1);
	*data = ft_substr(file, j, len);
	if (!(*data))
		return (error(cub3d, "Malloc fail", NULL));
	return (0);
}

static void	skip_space(char	*file, int *len)
{
	while (ft_isspace(file[*len]))
		(*len)++;
}

int	search_kind_str(t_cub *cub3d, t_data *data, char **file, int *i)
{
	int	j;

	j = 0;
	skip_space(file[*i], &j);
	if (ft_strncmp(&file[*i][j], "", 1) == 0)
		return (0);
	else if (ft_strncmp(&file[*i][j], "NO", 2) == 0)
		return (search_str(cub3d, &data->no, &file[*i][j + 2], 0));
	else if (ft_strncmp(&file[*i][j], "EA", 2) == 0)
		return (search_str(cub3d, &data->ea, &file[*i][j + 2], 0));
	else if (ft_strncmp(&file[*i][j], "SO", 2) == 0)
		return (search_str(cub3d, &data->so, &file[*i][j + 2], 0));
	else if (ft_strncmp(&file[*i][j], "WE", 2) == 0)
		return (search_str(cub3d, &data->we, &file[*i][j + 2], 0));
	else if (ft_strncmp(&file[*i][j], "F", 1) == 0)
		return (recup_floor_ceiling(cub3d, &data->floor, &file[*i][j + 1],
			&cub3d->draw->floor));
	else if (ft_strncmp(&file[*i][j], "C", 1) == 0)
		return (recup_floor_ceiling(cub3d, &data->ceiling, &file[*i][j + 1],
			&cub3d->draw->ceiling));
	else if (verif_first_line(file[*i], 0))
		return (verif_start_map(cub3d, data, file, i));
	else
		return (error(cub3d, "Argument in file no valid", NULL));
	return (0);
}
