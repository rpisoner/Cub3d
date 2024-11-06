/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:27:18 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/06 11:39:47 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	search_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while(game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S' || game->map.map[i][j] == 'E' || game->map.map[i][j] == 'W')
			{
				game->player.x = j * BLOCK_SIZE;
				game->player.y = i * BLOCK_SIZE;
			}
		}
	}
}

void	init_player(t_game *game)
{
	game->player.x = WIDTH / 2;
	game->player.y = HEIGHT / 2;
	search_player(game);
	game->player.angle = M_PI;
	assing_initial_angle(game);
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.key_left = false;
	game->player.key_right = false;
	game->player.key_door = false;
	game->door_open = false;
	game->player.left_rotation = false;
	game->player.right_rotation = false;
}
