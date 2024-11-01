/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:27:18 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/01 17:22:37 by jolivare         ###   ########.fr       */
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

void	move_player(t_game *game)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 2;
	angle_speed = 0.03;
	cos_angle = cos(game->player.angle);
	sin_angle = sin(game->player.angle);

	if (game->player.left_rotation)
		game->player.angle -= angle_speed;
	if (game->player.right_rotation)
		game->player.angle += angle_speed;
	if (game->player.angle > 2 * M_PI)
		game->player.angle = 0;
	if (game->player.angle < 0)
		game->player.angle = 2 * M_PI;
	if (game->player.key_up && !is_wall_up(game, speed, cos_angle, sin_angle))
	{
		game->player.x += cos_angle * speed;
		game->player.y += sin_angle * speed;
	}
	if (game->player.key_down && !is_wall_down(game, speed, cos_angle, sin_angle))
	{
		game->player.x -= cos_angle * speed;
		game->player.y -= sin_angle * speed;
	}
	if (game->player.key_left && !is_wall_left(game, speed, cos_angle, sin_angle))
	{
		game->player.x += sin_angle * speed;
		game->player.y -= cos_angle * speed;
	}
	if (game->player.key_right && !is_wall_right(game, speed, cos_angle, sin_angle))
	{
		game->player.x -= sin_angle * speed;
		game->player.y += cos_angle * speed;
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
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S' || game->map.map[i][j] == 'E' || game->map.map[i][j] == 'W')
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
	game->player.angle = M_PI;
	assing_initial_angle(game);
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.left_rotation = false;
	game->player.right_rotation = false;
}
