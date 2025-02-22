/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:53:38 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/09 17:41:16 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_wall_up(t_game *game, int speed, float cos_angle, float sin_angle)
{
	float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	new_x = game->player.x + cos_angle * speed;
	new_y = game->player.y + sin_angle * speed;
	map_x = (int)new_x / BLOCK_SIZE;
	map_y = (int)new_y / BLOCK_SIZE;
	if (game->map.map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	is_wall_down(t_game *game, int speed, float cos_angle, float sin_angle)
{
	float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	new_x = game->player.x - cos_angle * speed;
	new_y = game->player.y - sin_angle * speed;
	map_x = (int)new_x / BLOCK_SIZE;
	map_y = (int)new_y / BLOCK_SIZE;
	if (game->map.map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	is_wall_left(t_game *game, int speed, float cos_angle, float sin_angle)
{
	float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	new_x = game->player.x + sin_angle * speed;
	new_y = game->player.y - cos_angle * speed;
	map_x = (int)new_x / BLOCK_SIZE;
	map_y = (int)new_y / BLOCK_SIZE;
	if (game->map.map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	is_wall_right(t_game *game, int speed, float cos_angle, float sin_angle)
{
	float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	new_x = game->player.x - sin_angle * speed;
	new_y = game->player.y + cos_angle * speed;
	map_x = (int)new_x / BLOCK_SIZE;
	map_y = (int)new_y / BLOCK_SIZE;
	if (game->map.map[map_y][map_x] == '1')
		return (1);
	return (0);
}
