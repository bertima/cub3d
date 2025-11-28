/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:44:51 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/25 13:19:42 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	error_line(t_cub *cub3d, int i)
{
	char	*ligne;

	ligne = ft_itoa(i + 1);
	if (!ligne)
		return (error(cub3d, "Malloc fail", NULL));
	ft_putstr_fd("ligne : ", 2);
	ft_putstr_fd(ligne, 2);
	ft_putstr_fd("\n", 2);
	free(ligne);
	return (1);
}

int	error_sys(t_cub *cub3d, char *av)
{
	ft_putstr_fd("Error\n", 2);
	perror(av);
	free_struct(cub3d);
	return (1);
}

int	error(t_cub *cub3d, char *str, char *message)
{
	ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, 2);
	if (message)
		ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	free_struct(cub3d);
	return (1);
}
