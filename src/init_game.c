/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:04:32 by rpisoner          #+#    #+#             */
/*   Updated: 2024/12/19 11:51:10 by jolivare         ###   ########.fr       */
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
	game->player.key_door = false;
	game->player.left_rotation = false;
	game->player.right_rotation = false;
}

void	init_game(t_game *game)
{
	game->north_texture = NULL;
	game->south_texture = NULL;
	game->east_texture = NULL;
	game->west_texture = NULL;
	game->door = NULL;
	game->floor_color = 0;
	game->ceiling_color = 0;
	game->map.textures_ready = false;
	game->speed = 4;
	init_player(game);
}
