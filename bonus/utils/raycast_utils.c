/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:39:53 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/21 12:11:10 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	assign_orientation(t_game *game, int side, float cos_angle,
		float sin_angle)
{
	if (side == 0)
		assign_e_w(game, cos_angle);
	else
		assign_n_s(game, sin_angle);
}

static int	chech_ray_collision(t_game *game)
{
	int		map_x;
	int		map_y;

	game->is_door = 0;
	map_x = (int)(game->vars.ray_x / BLOCK_SIZE);
	map_y = (int)(game->vars.ray_y / BLOCK_SIZE);
	if (check_door_touch(map_x, map_y, game))
	{
		game->vars.wall_x = game->vars.ray_x;
		game->vars.wall_y = game->vars.ray_y;
		game->is_door = 1;
		return (1);
	}
	if (game->map.map[map_y][map_x] == '1')
	{
		game->vars.wall_x = game->vars.ray_x;
		game->vars.wall_y = game->vars.ray_y;
		return (1);
	}
	return (0);
}

void	dda(t_game *game, float cos_angle, float sin_angle)
{
	while (1)
	{
		if (game->vars.side_x < game->vars.side_y)
		{
			game->vars.side_x += game->vars.delta_x;
			game->vars.ray_x = game->player.x + cos_angle * game->vars.side_x;
			game->vars.side = 0;
		}
		else
		{
			game->vars.side_y += game->vars.delta_y;
			game->vars.ray_y = game->player.y + sin_angle * game->vars.side_y;
			game->vars.side = 1;
		}
		if (chech_ray_collision(game))
			break ;
	}
	game->vars.ray_x = game->vars.wall_x;
	game->vars.ray_y = game->vars.wall_y;
}

void	choose_ray_direction(t_game *game, float cos_angle, float sin_angle)
{
	if (cos_angle > 0)
		game->vars.step_x = 1;
	else
		game->vars.step_x = -1;
	if (sin_angle > 0)
		game->vars.step_y = 1;
	else
		game->vars.step_y = -1;
	if (game->vars.step_x == 1)
		game->vars.side_x = ((int)(game->vars.ray_x / BLOCK_SIZE) + 1 - \
		game->vars.ray_x / BLOCK_SIZE) * game->vars.delta_x;
	else
		game->vars.side_x = (game->vars.ray_x / BLOCK_SIZE - \
			(int)(game->vars.ray_x / BLOCK_SIZE)) * game->vars.delta_x;
	if (game->vars.step_y == 1)
		game->vars.side_y = ((int)(game->vars.ray_y / BLOCK_SIZE) + 1 - \
		game->vars.ray_y / BLOCK_SIZE) * game->vars.delta_y;
	else
		game->vars.side_y = (game->vars.ray_y / BLOCK_SIZE - \
		(int)(game->vars.ray_y / BLOCK_SIZE)) * game->vars.delta_y;
}
