/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_compass_textures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:08:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/04 15:21:13 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_north_compass(t_game *game, int width, int height)
{
	game->north_compass = mlx_xpm_file_to_image(game->window.mlx, \
		COMPASS_NORTH, &width, &height);
	if (game->north_compass == NULL)
	{
		printf("Error assigning North compass texture\n");
		exit (1);
	}
	game->north_west_compass = mlx_xpm_file_to_image(game->window.mlx, \
		COMPASS_NORTH_WEST, &width, &height);
	if (game->north_west_compass == NULL)
	{
		printf("Error assigning North west compass texture\n");
		exit (1);
	}
	game->north_east_compass = mlx_xpm_file_to_image(game->window.mlx, \
		COMPASS_NORTH_EAST, &width, &height);
	if (game->north_east_compass == NULL)
	{
		printf("Error assigning North east compass texture\n");
		exit (1);
	}
}

void	init_south_compass(t_game *game, int width, int height)
{
	game->south_compass = mlx_xpm_file_to_image(game->window.mlx, \
		COMPASS_SOUTH, &width, &height);
	if (game->south_compass == NULL)
	{
		printf("Error assigning South compass\n");
		exit (1);
	}
	game->south_west_compass = mlx_xpm_file_to_image(game->window.mlx, \
		COMPASS_SOUTH_WEST, &width, &height);
	if (game->south_west_compass == NULL)
	{
		printf("Error assigning South West compass\n");
		exit (1);
	}
	game->south_east_compass = mlx_xpm_file_to_image(game->window.mlx, \
		COMPASS_SOUTH_EAST, &width, &height);
	if (game->south_east_compass == NULL)
	{
		printf("Error asigning South East Compass\n");
		exit (1);
	}
}

void	init_west_compass(t_game *game, int width, int height)
{
	game->west_compass = mlx_xpm_file_to_image(game->window.mlx, \
		COMPASS_WEST, &width, &height);
	if (game->west_compass == NULL)
	{
		printf("Error assigning West compass tetxture\n");
		exit (1);
	}
}

void	init_east_compass(t_game *game, int width, int height)
{
	game->east_compass = mlx_xpm_file_to_image(game->window.mlx, \
		COMPASS_EAST, &width, &height);
	if (game->west_compass == NULL)
	{
		printf("Error assigning East compass texture\n");
		exit (1);
	}
}
