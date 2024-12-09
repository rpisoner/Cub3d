/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:05:50 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/09 18:35:29 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	door_count(t_game *game)
{
	int	i;
	int	j;
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
		print_errors(1);
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

int	check_door_collision(t_game *game, int x, int y)
{
	int	i;

	i = -1;
	while (++i < game->door_count)
	{
		if (x == game->door[i].x && y == game->door[i].y
			&& !game->door[i].open)
			return (1);
	}
	return (0);
}

void	open_door(t_game *game, float cos_angle, float sin_angle, int speed)
{
	int		i;
	float	new_x;
	float	new_y;
	int		x;
	int		y;
	
	new_x = game->player.x + sin_angle * speed;
	new_y = game->player.y + cos_angle * speed;
	x = (int)new_x / BLOCK_SIZE;
	y = (int)new_y / BLOCK_SIZE;
	i = -1;
	while (++i < game->door_count)
	{
		printf("game_door x: %d\n", game->door[i].x);
		printf("map x: %d\n", x);
		if (x == game->door[i].x && y == game->door[i].y
			&& !game->door[i].open)
		{
			printf("Entra en el if\n");
			game->door[i].open = true;
		}
		else if (x == game->door[i].x && y == game->door[i].y
			&& game->door[i].open)
			game->door[i].open = false;
	}
}
