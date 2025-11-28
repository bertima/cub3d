/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:45:44 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/26 11:50:28 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	recup_file(t_cub *cub3d, t_data *data, char *arg)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (error_sys(cub3d, arg));
	str = get_next_line(fd);
	while (str)
	{
		data->file[i] = ft_substr(str, 0, (ft_strlen(str) - 1));
		if (!data->file[i])
		{
			ft_free(&str);
			close(fd);
			return (error_sys(cub3d, ""));
		}
		ft_free(&str);
		i++;
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int	len_file(t_cub *cub3d, int *len, char *arg)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (error_sys(cub3d, arg));
	str = get_next_line(fd);
	while (str)
	{
		ft_free(&str);
		i++;
		(*len)++;
		str = get_next_line(fd);
		if (str && str[ft_strlen(str) - 1] != '\n')
		{
			free(str);
			close(fd);
			return (error(cub3d, "NL for EOF requiert", NULL));
		}
	}
	close(fd);
	return (0);
}

static int	recup_file_verif_data(t_cub *cub3d, char *arg)
{
	if (recup_file(cub3d, cub3d->data, arg))
		return (1);
	if (dispatch(cub3d, cub3d->data, 0))
		return (1);
	if (verif_wall(cub3d))
		return (1);
	if (!cub3d->data->map)
		return (error(cub3d, "No map no game", NULL));
	return (0);
}

static int	verif_file(t_cub *cub3d, char *arg)
{
	int	i;

	i = ft_strlen(arg);
	if (!arg)
		return (error(cub3d, "Arg NULL", NULL));
	if (i < 5)
		return (error(cub3d, "File .cub requiert for project", NULL));
	if (strncmp(&arg[i - 4], ".cub", 5) != 0)
		return (error(cub3d, "File .cub requiert for project", NULL));
	return (0);
}

int	recup_data(t_cub *cub3d, char *arg)
{
	int	len;

	len = 0;
	if (verif_file(cub3d, arg))
		return (1);
	if (len_file(cub3d, &len, arg))
		return (1);
	cub3d->data->file = ft_calloc(len + 1, sizeof(char *));
	if (!cub3d->data->file)
		return (error(cub3d, "Malloc fail", NULL));
	if (recup_file_verif_data(cub3d, arg))
		return (1);
	pos_player_len_map(cub3d, cub3d->v);
	return (0);
}
