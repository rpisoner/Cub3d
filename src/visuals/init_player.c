/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:27:18 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/27 11:05:11 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	key_press(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == D)
		player->key_right = true;
	if (keycode == LEFT)
		player->left_rotation = true;
	if (keycode == RIGHT)
		player->right_rotation = true;
	if (keycode == ESC)
		exit_game();
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
	if (keycode == LEFT)
		player->left_rotation = false;
	if (keycode == RIGHT)
		player->right_rotation = false;
	return (0);
}

void	move_player(t_player *player)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 2;
	angle_speed = 0.03;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);

	if (player->left_rotation)
		player->angle -= angle_speed;
	if (player->right_rotation)
		player->angle += angle_speed;
	if (player->angle > 2 * M_PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * M_PI;
	if (player->key_up)
	{
		player->x += cos_angle * speed;
		player->y += sin_angle * speed;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * speed;
		player->y -= sin_angle * speed;
	}
	if (player->key_left)
	{
		player->x += sin_angle * speed;
		player->y -= cos_angle * speed;
	}
	if (player->key_right)
	{
		player->x -= sin_angle * speed;
		player->y += cos_angle * speed;
	}
}

void	search_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while(game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'P')
			{
				game->player.x = j * BLOCK_SIZE;
				game->player.y = i * BLOCK_SIZE;
			}
		}
	}
}

void	init_player(t_game *game)
{
	game->player.x = WIDTH / 2;
	game->player.y = HEIGHT / 2;
	search_player(game);
	game->player.angle = M_PI / 2;
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.left_rotation = false;
	game->player.right_rotation = false;
}
