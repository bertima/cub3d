/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:44:06 by cowillem          #+#    #+#             */
/*   Updated: 2026/09/01 15:10:04 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	field_empty(t_cub*cub3d, t_data *data)
{
	char	*error_str;

	error_str = "requiert file .xpm : ";
	if (!data->ea)
		return (error(cub3d, error_str, "EA"));
	if (!data->no)
		return (error(cub3d, error_str, "NO"));
	if (!data->so)
		return (error(cub3d, error_str, "SO"));
	if (!data->we)
		return (error(cub3d, error_str, "WE"));
	error_str = "requiert data for rgb 0 -> 255 ex : \"F 255,000,255\" : ";
	if (!data->floor)
		return (error(cub3d, error_str, "Floor"));
	error_str = "requiert data for rgb 0 -> 255 ex : \"C 255,000,255\" : ";
	if (!data->ceiling)
		return (error(cub3d, error_str, "Ceiling"));
	return (0);
}

static int	verif_directory(t_cub *cub3d, t_data *data, int i)
{
	char	*error_str;

	error_str = "Empty file or directory are invalid";
	if (!data->file[i])
		return (error(cub3d, error_str, NULL));
	return (0);
}

static int	verif_file_empty(t_cub *cub3d, t_data *data)
{
	if (!data->ea && !data->no && !data->so && !data->we
		& !data->floor && !data->ceiling && !data->map)
		return (error(cub3d, "File empty (only isspace)", NULL));
	return (0);
}

int	dispatch(t_cub *cub3d, t_data *data, int i)
{
	int	len;
	int	result;

	if (verif_directory(cub3d, data, i))
		return (1);
	len = ft_len_array(data->file);
	while (i < len)
	{
		if (!data->file[i])
			return (error(cub3d, "data->file problem", NULL));
		result = search_kind_str(cub3d, data, data->file, &i);
		if (result == 1)
			return (error_line(cub3d, i));
		else if (result == 2)
			return (1);
		i++;
	}
	if (data->file[i])
		return (error(cub3d, "NL requiert for EOF", NULL));
	if (verif_file_empty(cub3d, data))
		return (1);
	if (field_empty(cub3d, cub3d->data))
		return (1);
	return (0);
}
