/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:52:56 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/19 11:46:22 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#include "../../inc/cub3d.h"

static void	move_player_forward(t_game *game, float cos_angle, \
	float sin_angle, int speed)
{
	game->player.x += cos_angle * speed;
	game->player.y += sin_angle * speed;
}

static void	move_player_backwards(t_game *game, float cos_angle, \
	float sin_angle, int speed)
{
	game->player.x -= cos_angle * speed;
	game->player.y -= sin_angle * speed;
}

static void	move_player_left(t_game *game, float cos_angle, \
	float sin_angle, int speed)
{
	game->player.x += sin_angle * speed;
	game->player.y -= cos_angle * speed;
}

static void	move_player_right(t_game *game, float cos_angle, \
	float sin_angle, int speed)
{
	game->player.x -= sin_angle * speed;
	game->player.y += cos_angle * speed;
}

void	move_player(t_game *game)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(game->player.angle);
	sin_angle = sin(game->player.angle);
	check_angle(game);
	if (game->player.key_door)
		open_door(game);
	if (game->player.key_up && !is_wall_up(game, game->speed, \
		cos_angle, sin_angle) && \
		!is_door_up(game, game->speed, cos_angle, sin_angle))
		move_player_forward(game, cos_angle, sin_angle, game->speed);
	if (game->player.key_down && !is_wall_down(game, game->speed, \
		cos_angle, sin_angle) && \
		!is_door_down(game, game->speed, cos_angle, sin_angle))
		move_player_backwards(game, cos_angle, sin_angle, game->speed);
	if (game->player.key_left && !is_wall_left(game, game->speed, \
		cos_angle, sin_angle) && \
		!is_door_left(game, game->speed, cos_angle, sin_angle))
		move_player_left(game, cos_angle, sin_angle, game->speed);
	if (game->player.key_right && !is_wall_right(game, game->speed, \
		cos_angle, sin_angle) && \
		!is_door_right(game, game->speed, cos_angle, sin_angle))
		move_player_right(game, cos_angle, sin_angle, game->speed);
}
