/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:05:50 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/04 11:58:31 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	door_count(t_game *game)
{
	int i;
	int j;
	int	count;

	i = -1;
	count = 0;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'D')
				count++;	
		}
	}
	game->door_count = count;
	return (count);
}

int	check_door_touch(int ray_x, int ray_y, t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->door_count)
	{
		if (ray_x == game->door[i].x && ray_y == game->door[i].y 
			&& !game->door[i].open)
			{
				game->orientation = 5;	
				return (1);
			}
	}
	return (0);
}

void	init_door(t_game *game)
{
	int	door_index;
	int	i;
	int	j;

	door_index = 0;
	if (door_count(game) != 0)
		game->door = malloc(sizeof(t_door) * game->door_count);
	if (game->door == NULL)
	{
		printf("Malloc error\n");
		exit (1);
	}
	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'D')
			{
				game->door[door_index].x = j;
				game->door[door_index].y = i;
				game->door[door_index].open = false;
				door_index++;
			}
		}
	}
}
