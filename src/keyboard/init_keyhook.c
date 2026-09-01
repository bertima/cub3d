/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keyhook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:56:06 by bertrmar          #+#    #+#             */
/*   Updated: 2026/09/01 15:06:14 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	handle_key_mini_map_fps_sprint(int key, t_cub *cub3d)
{
	if (key == 109)
	{
		if (cub3d->key->mini_map == 2)
			cub3d->key->mini_map = 0;
		else
			cub3d->key->mini_map++;
	}
	if (key == 102)
	{
		if (!cub3d->key->fps)
			cub3d->key->fps = 1;
		else
			cub3d->key->fps = 0;
	}
	if (key == 65505)
	{
		if (!cub3d->key->sprint)
			cub3d->key->sprint = 1;
		else
			cub3d->key->sprint = 0;
	}
}

static int	key_release(int key, t_cub *cub3d)
{
	handle_key_mini_map_fps_sprint(key, cub3d);
	if (key == 119)
		cub3d->key->up = 0;
	if (key == 65361)
		cub3d->key->left_rot = 0;
	if (key == 115)
		cub3d->key->down = 0;
	if (key == 65363)
		cub3d->key->right_rot = 0;
	if (key == 100)
		cub3d->key->right = 0;
	if (key == 97)
		cub3d->key->left = 0;
	if (key == 118)
	{
		if (cub3d->key->vue)
			cub3d->key->vue = 0;
		else
			cub3d->key->vue++;
	}
	return (0);
}

static int	key_press(int key, t_cub *cub3d)
{
	if (key == 65307)
		exit_game(cub3d);
	if (cub3d->key->mini_map != 2)
	{
		if (key == 119)
			cub3d->key->up = 1;
		if (key == 65361)
			cub3d->key->left_rot = 1;
		if (key == 115)
			cub3d->key->down = 1;
		if (key == 65363)
			cub3d->key->right_rot = 1;
		if (key == 100)
			cub3d->key->right = 1;
		if (key == 97)
			cub3d->key->left = 1;
	}
	return (0);
}

static int	update_keyhook(t_cub *cub3d)
{
	if (cub3d->key->esc)
		exit_game(cub3d);
	if (cub3d->key->mini_map != 2)
	{
		if (cub3d->key->up)
			up_move(cub3d);
		if (cub3d->key->left_rot)
			left_rotate(cub3d);
		if (cub3d->key->down)
			down_move(cub3d);
		if (cub3d->key->right_rot)
			right_rotate(cub3d);
		if (cub3d->key->right)
			right_move(cub3d);
		if (cub3d->key->left)
			left_move(cub3d);
	}
	core_loop(cub3d);
	return (0);
}

void	hook_mlx(t_cub *cub3d)
{
	mlx_hook(cub3d->mlx->window, 17, 0, exit_game, cub3d);
	mlx_hook(cub3d->mlx->window, 2, 1L << 0, key_press, cub3d);
	mlx_hook(cub3d->mlx->window, 3, 1L << 1, key_release, cub3d);
	mlx_loop_hook(cub3d->mlx->mlx, update_keyhook, cub3d);
}
