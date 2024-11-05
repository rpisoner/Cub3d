/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:55:04 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/05 12:40:56 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_player_on_minimap(t_game *game)
{
	int player_x;
	int player_y;

	player_x = game->player.x * MINIMAP_SCALE;
	player_y = game->player.y * MINIMAP_SCALE;
	draw_square(player_x, player_y, 10, 0x00FF00, game);
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
				draw_square(x * MINIMAP_BLOCK_SIZE, y * MINIMAP_BLOCK_SIZE, MINIMAP_BLOCK_SIZE, color, game);
			if (game->map.map[y][x] == 'D')
				draw_square(x * MINIMAP_BLOCK_SIZE, y * MINIMAP_BLOCK_SIZE, MINIMAP_BLOCK_SIZE, door_color, game);
		}
	}
	draw_player_on_minimap(game);
}


bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK_SIZE;
	y = py / BLOCK_SIZE;
	if (game->map.map[y][x] == '1')
	{
		if (py - (y * BLOCK_SIZE) < 1)
			game->orientation = 1;
		else if (py - (y * BLOCK_SIZE) > BLOCK_SIZE - 1)
			game->orientation = 2;
		else if (px - (x * BLOCK_SIZE) <= 1)
            game->orientation = 3;
        else if (px - (x * BLOCK_SIZE) >= BLOCK_SIZE - 1)
            game->orientation = 4;
		return (true);
	}
	else if (game->map.map[y][x] == 'D' && !game->door_open)
	{
		game->orientation = 5;
		return(true);
	}
	return (false);
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_distance(float x1, float y1, float x2, float y2, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
	float	dist;
	int		color;
	int		start_y;
	int		end;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;
	while (!touch(ray_x, ray_y, game))
	{
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	dist = fixed_distance(player->x, player->y, ray_x, ray_y, game);
	start_y = (HEIGHT - ((BLOCK_SIZE / dist) * (WIDTH / 2))) / 2;
	end	= start_y + ((BLOCK_SIZE / dist) * (WIDTH / 2));
	if (game->orientation == 1)
		color = COLOR_NORTH;
	else if (game->orientation == 2)
		color = COLOR_SOUTH;
	else if (game->orientation == 3)
		color = COLOR_EAST;
	else if (game->orientation == 4)
		color = COLOR_WEST;
	else if (game->orientation == 5 && !game->door_open)
		color = COLOR_DOOR;
	while (start_y < end)
	{
		put_pixel(i, start_y, color, game);
		start_y++;
	}
}
