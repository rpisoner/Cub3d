/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:47:02 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/21 12:13:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	assign_e_w(t_game *game, float cos_angle)
{
	if (cos_angle > 0)
	{
		game->orientation = 3;
		game->door_orientation = 3;
	}
	else
	{
		game->door_orientation = 4;
		game->orientation = 4;
	}
}

void	assign_n_s(t_game *game, float sin_angle)
{
	if (sin_angle > 0)
	{
		game->orientation = 1;
		game->door_orientation = 1;
	}
	else
	{
		game->orientation = 2;
		game->door_orientation = 2;
	}
}

int	check_door_open(t_game *game, int x, int y)
{
	int	i;

	i = -1;
	while (++i < game->door_count)
	{
		if (x == game->door[i].x && y == game->door[i].y
			&& !game->door[i].open)
			return (1);
	}
	return (0);
}

void	draw_door_on_minimap(t_game *game, int x, int y)
{
	int	i;
	int	color;
	int	size;

	size = MINIMAP_BLOCK_SIZE;
	color = 0x00FF00;
	i = -1;
	while (++i < size)
		put_pixel(x + i, y, color, game);
	i = -1;
	while (++i < size)
		put_pixel(x, y + i, color, game);
	i = -1;
	while (++i < size)
		put_pixel(x + size, y + i, color, game);
	i = -1;
	while (++i < size)
		put_pixel(x + i, y + size, color, game);
}
