/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:56:33 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/09 18:22:42 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == D)
		game->player.key_right = true;
	if (keycode == E)
		game->player.key_door = true;
	if (keycode == LEFT)
		game->player.left_rotation = true;
	if (keycode == RIGHT)
		game->player.right_rotation = true;
	if (keycode == ESC)
		exit_game(game);
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == E)
		player->key_door = false;
	if (keycode == LEFT)
		player->left_rotation = false;
	if (keycode == RIGHT)
		player->right_rotation = false;
	return (0);
}
