/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_collisions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:41:47 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/09 17:50:06 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_door_up(t_game *game, int speed, float cos_angle, float sin_angle)
{
	float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	new_x = game->player.x + cos_angle * speed;
	new_y = game->player.y + sin_angle * speed;
	map_x = (int)new_x / BLOCK_SIZE;
	map_y = (int)new_y / BLOCK_SIZE;
	if (game->map.map[map_y][map_x] == 'D')
	{
		if (check_door_collision(game, map_x, map_y))
			return (1);
	}
	return (0);
}

int	is_door_down(t_game *game, int speed, float cos_angle, float sin_angle)
{
		float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	new_x = game->player.x - cos_angle * speed;
	new_y = game->player.y - sin_angle * speed;
	map_x = (int)new_x / BLOCK_SIZE;
	map_y = (int)new_y / BLOCK_SIZE;
	if (game->map.map[map_y][map_x] == 'D')
	{
		if (check_door_collision(game, map_x, map_y))
			return (1);
	}
	return (0);
}

int	is_door_left(t_game *game, int speed, float cos_angle, float sin_angle)
{
	float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	new_x = game->player.x + sin_angle * speed;
	new_y = game->player.y - cos_angle * speed;
	map_x = (int)new_x / BLOCK_SIZE;
	map_y = (int)new_y / BLOCK_SIZE;
	if (game->map.map[map_y][map_x] == 'D')
	{
		if (check_door_collision(game, map_x, map_y))
			return (1);
	}
	return (0);
}

int	is_door_right(t_game *game, int speed, float cos_angle, float sin_angle)
{
	float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	new_x = game->player.x - sin_angle * speed;
	new_y = game->player.y + cos_angle * speed;
	map_x = (int)new_x / BLOCK_SIZE;
	map_y = (int)new_y / BLOCK_SIZE;
	if (game->map.map[map_y][map_x] == 'D')
	{
		if (check_door_collision(game, map_x, map_y))
			return (1);
	}
	return (0);
}
