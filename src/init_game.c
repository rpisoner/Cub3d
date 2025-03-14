/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:04:32 by rpisoner          #+#    #+#             */
/*   Updated: 2025/02/22 10:06:56 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_player(t_game *game)
{
	game->player.x = WIDTH / 2;
	game->player.y = HEIGHT / 2;
	game->player.angle = M_PI;
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.key_left = false;
	game->player.key_right = false;
	game->player.left_rotation = false;
	game->player.right_rotation = false;
}

void	init_game(t_game *game)
{
	game->north_texture = NULL;
	game->south_texture = NULL;
	game->east_texture = NULL;
	game->west_texture = NULL;
	game->floor_str = NULL;
	game->ceiling_str = NULL;
	game->floor_color = 0;
	game->ceiling_color = 0;
	game->map.textures_ready = false;
	game->speed = 4;
	game->limit_steps = 0;
	init_player(game);
}
