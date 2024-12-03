/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:52:56 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/03 10:54:36 by jolivare         ###   ########.fr       */
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

static void	move_player_backward(t_game *game, float cos_angle, \
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
	int		speed;
	float	cos_angle;
	float	sin_angle;

	speed = 2;
	cos_angle = cos(game->player.angle);
	sin_angle = sin(game->player.angle);
	check_angle(game);
	if (game->player.key_up && !is_wall_up(game, speed, \
		cos_angle, sin_angle))
		move_player_forward(game, cos_angle, sin_angle, speed);
	if (game->player.key_down && !is_wall_down(game, speed, \
		cos_angle, sin_angle))
		move_player_backward(game, cos_angle, sin_angle, speed);
	if (game->player.key_left && !is_wall_left(game, speed, \
		cos_angle, sin_angle))
		move_player_left(game, cos_angle, sin_angle, speed);
	if (game->player.key_right && !is_wall_right(game, speed, \
		cos_angle, sin_angle))
		move_player_right(game, cos_angle, sin_angle, speed);
}
