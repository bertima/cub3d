/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:31:18 by bertrmar          #+#    #+#             */
/*   Updated: 2025/11/26 09:21:22 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	verif_range_color(t_cub *cub3d, int *tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (tab[i] < 0 || tab[i] > 255)
			return (error(cub3d, "Value for RGB : 0 -> 255", NULL));
		i++;
	}
	return (0);
}

static int	verif_len_arg(t_cub *cub3d, char *val)
{
	int		i;
	int		count;
	char	*error_s;

	count = 0;
	i = 0;
	while (val[i])
	{
		if (val[i] == ',')
			count++;
		i++;
	}
	error_s = "Only three arg numeric for RGB between 0->255 : \"255,000,255\"";
	if (count > 2)
		return (error(cub3d, error_s, NULL));
	if (count < 2)
		return (error(cub3d, error_s, NULL));
	return (0);
}

static int	verif_len_color(t_cub *cub3d, char **str, int i, int j)
{
	char	*error_s;

	error_s = "Only three arg numeric for RGB between 0->255 : \"255,000,255\"";
	if (!str[0] || !str[1] || !str[2])
		return (error(cub3d, error_s, NULL));
	while (i < 3)
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
				return (error(cub3d, error_s, NULL));
			j++;
		}
		i++;
	}
	return (0);
}

static int	recup_rgb_value(t_cub *cub3d, char *val, int *tab)
{
	char	**str;

	str = ft_split(val, ',');
	if (!str)
		return (error(cub3d, "Malloc fail", NULL));
	if (verif_len_arg(cub3d, val))
		return (ft_free_array(str), 1);
	if (verif_len_color(cub3d, str, 0, 0))
		return (ft_free_array(str), 1);
	if (ft_atoi(str[0], &tab[0]))
		return (error(cub3d, "Value in RGB superior to the max int", NULL));
	if (ft_atoi(str[1], &tab[1]))
		return (error(cub3d, "Value in RGB superior to the max int", NULL));
	if (ft_atoi(str[2], &tab[2]))
		return (error(cub3d, "Value in RGB superior to the max int", NULL));
	if (verif_range_color(cub3d, tab))
		return (ft_free_array(str), 1);
	return (ft_free_array(str), 0);
}

int	verif_color(t_cub *cub3d, char *val, int *arg)
{
	int	color[3];

	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	if (recup_rgb_value(cub3d, val, color))
		return (1);
	*arg = (color[0] << 16) | (color[1] << 8) | color[2];
	return (0);
}
