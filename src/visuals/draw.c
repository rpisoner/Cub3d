/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:55:04 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/19 02:07:53 by jolivare         ###   ########.fr       */
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
	float	cos_angle;
	float	sin_angle;
	float	dist;

	cos_angle = cos(ray_angle);
	sin_angle = sin(ray_angle);
	game->vars.ray_x = game->player.x;
	game->vars.ray_y = game->player.y;
	game->vars.delta_x = fabsf(1 / cos_angle);
	game->vars.delta_y = fabsf(1 / sin_angle);
	choose_ray_direction(game, cos_angle, sin_angle);
	dda(game, cos_angle, sin_angle);
	dist = fixed_distance(game->player.x, game->player.y, game);
	assign_orientation(game, game->vars.side, cos_angle, sin_angle);
	render(game, dist, cos_angle, sin_angle);
}
