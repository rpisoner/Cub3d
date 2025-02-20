/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:35:45 by rpisoner          #+#    #+#             */
/*   Updated: 2025/02/20 19:51:20 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	draw_walls(int x, int y, t_game *game)
{
	int	i;
	int	color;
	int	size;

	size = MINIMAP_BLOCK_SIZE;
	color = 0xFF0000;
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

static void	draw_player(int x, int y, t_game *game)
{
	int	i;
	int	size;
	int	color;

	size = 10;
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

void	draw_player_on_minimap(t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = game->player.x * MINIMAP_SCALE;
	player_y = game->player.y * MINIMAP_SCALE;
	draw_player(player_x, player_y, game);
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
	int	y;
	int	x;

	draw_minimap_background(game);
	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == '1')
				draw_walls(x * MINIMAP_BLOCK_SIZE, y * MINIMAP_BLOCK_SIZE,
					game);
		}
	}
	draw_player_on_minimap(game);
}
