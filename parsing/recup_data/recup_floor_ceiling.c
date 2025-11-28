/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:11:07 by bertrmar          #+#    #+#             */
/*   Updated: 2025/11/26 10:02:54 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	skip_space(t_cub *cub3d, char *file, int *j)
{
	char	*error_str;

	error_str = "Wrong arg for RGB, only accepted isspace, ',' and digit";
	while (ft_isspace(file[*j]))
		(*j)++;
	if (file[*j] == '\0')
		return (0);
	if (file[*j] != '\0' && !ft_isdigit(file[*j]) && file[*j] != ',')
		return (error(cub3d, error_str, NULL));
	return (0);
}

static int	alloc_data(t_cub *cub3d, char **data, char *file, int j)
{
	int	len;

	len = 0;
	while (file[j])
	{
		if (skip_space(cub3d, file, &j))
			return (1);
		while (ft_isdigit(file[j]))
		{
			j++;
			len++;
		}
		if (skip_space(cub3d, file, &j))
			return (1);
		if (file[j] != '\0' && file[j] != ',')
			return (error(cub3d, "Number must be separed by ','", NULL));
		if (file[j] == '\0')
			break ;
		len++;
		j++;
	}
	*data = calloc(len + 1, sizeof(char));
	if (!(*data))
		return (error(cub3d, "Malloc fail", NULL));
	return (0);
}

static int	adapt_str(t_cub *cub3d, char **data, char *file, int j)
{
	int	i;

	i = 0;
	if (alloc_data(cub3d, data, file, j))
		return (1);
	while (file[j])
	{
		while (file[j] && ft_isspace(file[j]))
			j++;
		while (file[j] && (ft_isdigit(file[j]) || file[j] == ','))
		{
			(*data)[i] = file[j];
			j++;
			i++;
		}
	}
	return (0);
}

int	recup_floor_ceiling(t_cub *cub3d, char **data, char *file, int *arg)
{
	int	len;
	int	j;
	int	count;

	count = 0;
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
	if (adapt_str(cub3d, data, file, j))
		return (1);
	if (verif_color(cub3d, *data, arg))
		return (1);
	return (0);
}
