/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:55:04 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/03 11:04:47 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_player_on_minimap(t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = game->player.x * MINIMAP_SCALE;
	player_y = game->player.y * MINIMAP_SCALE;
	draw_square(player_x, player_y, 7, 0x00FF00, game);
}

void	draw_minimap_background(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (game->map.y_size - 1) * MINIMAP_BLOCK_SIZE)
	{
		j = -1;
		while (++j < game->map.x_size * MINIMAP_BLOCK_SIZE)
			put_pixel(j, i, MINIMAP_BG_COLOR, game);
	}
}

void	draw_map(t_game *game)
{
	int	color;
	int	door_color;
	int	y;
	int	x;

	draw_minimap_background(game);
	color = 0xFF0000;
	door_color = 0x800080;
	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == '1')
				draw_square(x * MINIMAP_BLOCK_SIZE, y * MINIMAP_BLOCK_SIZE,
					MINIMAP_BLOCK_SIZE, color, game);
			if (game->map.map[y][x] == 'D' && !game->door_open)
				draw_square(x * MINIMAP_BLOCK_SIZE, y * MINIMAP_BLOCK_SIZE,
					MINIMAP_BLOCK_SIZE, door_color, game);
		}
	}
	draw_player_on_minimap(game);
}

bool	touch(t_game *game)
{
	int	x;
	int	y;

	x = game->vars.ray_x / BLOCK_SIZE;
	y = game->vars.ray_y / BLOCK_SIZE;
	if (game->map.map[y][x] == '1')
	{
		if (game->vars.ray_y - (y * BLOCK_SIZE) < 1)
			game->orientation = 1;
		else if (game->vars.ray_y - (y * BLOCK_SIZE) > BLOCK_SIZE - 1)
			game->orientation = 2;
		else if (game->vars.ray_x - (x * BLOCK_SIZE) < 1)
			game->orientation = 3;
		else if (game->vars.ray_x - (x * BLOCK_SIZE) > BLOCK_SIZE - 1)
			game->orientation = 4;
		return (true);
	}
	else if (game->map.map[y][x] == 'D' && !game->door_open)
	{
		game->orientation = 5;
		return (true);
	}
	return (false);
}

void	draw_line(t_game *game, float start_x)
{
	float	cos_angle;
	float	sin_angle;
	float	dist;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	game->vars.ray_x = game->player.x;
	game->vars.ray_y = game->player.y;
	while (!touch(game))
	{
		game->vars.ray_x += cos_angle;
		game->vars.ray_y += sin_angle;
	}
	dist = fixed_distance(game->player.x, game->player.y, game);
	render(game, dist);
}
