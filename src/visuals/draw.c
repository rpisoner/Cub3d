/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:55:04 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/18 23:56:33 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_player_on_minimap(t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = game->player.x * MINIMAP_SCALE + 10;
	player_y = game->player.y * MINIMAP_SCALE;
	draw_square(player_x, player_y, 7, 0x00FF00, game);
}

void	draw_minimap_background(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.y_size * MINIMAP_BLOCK_SIZE)
	{
		j = -1;
		while (++j < game->map.x_size * MINIMAP_BLOCK_SIZE)
			put_pixel(j, i, MINIMAP_BG_COLOR, game);
	}
}

void	draw_minimap(t_game *game)
{
	int	color;
	int	y;
	int	x;

	draw_minimap_background(game);
	color = 0xFF0000;
	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == '1')
				draw_square(x * MINIMAP_BLOCK_SIZE, y * MINIMAP_BLOCK_SIZE,
					MINIMAP_BLOCK_SIZE, color, game);
		}
	}
	draw_player_on_minimap(game);
}

void	draw_line(t_game *game, float ray_angle)
{
	float	cos_angle = cos(ray_angle);
	float	sin_angle = sin(ray_angle);

	game->vars.ray_x = game->player.x;
	game->vars.ray_y = game->player.y;
	float delta_x = fabsf(1 / cos_angle);
	float delta_y = fabsf(1 / sin_angle);
	int step_x = (cos_angle > 0) ? 1 : -1;
	int step_y = (sin_angle > 0) ? 1 : -1;
	float	side_x = (step_x == 1) ? ((int)(game->vars.ray_x / BLOCK_SIZE) + 1 - game->vars.ray_x / BLOCK_SIZE) * delta_x :
			(game->vars.ray_x / BLOCK_SIZE - (int)(game->vars.ray_x / BLOCK_SIZE)) * delta_x;
	float	side_y = (step_y == 1) ? ((int)(game->vars.ray_y / BLOCK_SIZE) + 1 - game->vars.ray_y / BLOCK_SIZE) * delta_y :
			(game->vars.ray_y / BLOCK_SIZE - (int)(game->vars.ray_y / BLOCK_SIZE)) * delta_y;

	int hit = 0;
	int side;
	float wall_x, wall_y;
	while (!hit)
	{
		if (side_x < side_y)
		{
			side_x += delta_x;
			game->vars.ray_x = game->player.x + cos_angle * side_x;
			side = 0;
		}
		else
		{
			side_y += delta_y;
			game->vars.ray_y = game->player.y + sin_angle * side_y;
			side = 1;
		}
		int map_x = (int)(game->vars.ray_x / BLOCK_SIZE);
		int map_y = (int)(game->vars.ray_y / BLOCK_SIZE);
		if (check_door_touch(map_x, map_y, game))
    	{
        	wall_x = game->vars.ray_x;
        	wall_y = game->vars.ray_y;
			side = 2;
        	hit = 1;
        	break;
    	}
		if (game->map.map[map_y][map_x] == '1')
		{
			wall_x = game->vars.ray_x;
			wall_y = game->vars.ray_y;
			hit = 1;
		}
	}
	game->vars.ray_x = wall_x;
	game->vars.ray_y = wall_y;
	float dist = fixed_distance(game->player.x, game->player.y, game);
	if (side == 0)
		game->orientation = (cos_angle > 0) ? 3 : 4;
	else if (side == 1)
		game->orientation = (sin_angle > 0) ? 1 : 2;
	else
		game->orientation = 5;
	render(game, dist);
}
