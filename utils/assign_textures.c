/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:36:08 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/29 15:49:54 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_north_texture(t_game *game, int size)
{
	game->north_texture = mlx_xpm_file_to_image(game->window.mlx, \
		NORTH_WALL, &size, &size);
	if (game->north_texture == NULL)
	{
		printf("Error assigning North texture\n");
		exit (1);
	}
}

void	init_south_texture(t_game *game, int size)
{
	game->south_texture = mlx_xpm_file_to_image(game->window.mlx, \
		SOUTH_WALL, &size, &size);
	if (game->south_texture == NULL)
	{
		printf("Error assigning south texture\n");
		exit (1);
	}
}

void	init_east_texture(t_game *game, int size)
{
	game->east_texture = mlx_xpm_file_to_image(game->window.mlx, \
		EAST_WALL, &size, &size);
	if (game->east_texture == NULL)
	{
		printf("Error assigning east texture\n");
		exit (1);
	}
}

void	init_west_texture(t_game *game, int size)
{
	game->west_texture = mlx_xpm_file_to_image(game->window.mlx, \
		WEST_WALL, &size, &size);
	if (game->west_texture == NULL)
	{
		printf("Error assigning west texture\n");
		exit (1);
	}
}

void	init_door_texture(t_game *game, int size)
{
	game->door_texture = mlx_xpm_file_to_image(game->window.mlx, \
		DOOR, &size, &size);
	if (game->door_texture == NULL)
	{
		printf("Error assigning door texture\n");
		exit (1);
	}
}
