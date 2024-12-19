/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:29:23 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/12 16:48:41 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	change_door_state(t_game *game, int x, int y, int index)
{
	if ((x + 1 == game->door[index].x && y == game->door[index].y
		&& !game->door[index].open) 
		|| (x - 1 == game->door[index].x && y - 1 == game->door[index].y
		&& !game->door[index].open))
		game->door[index].open = true;
	else if ((x + 1 == game->door[index].x && y == game->door[index].y
		&& game->door[index].open) 
		|| (x - 1 == game->door[index].x && y - 1 == game->door[index].y
		&& game->door[index].open))
		game->door[index].open = false;
}
