/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:06:10 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/13 16:56:08 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_texture_color(void *texture, int x, int y, int width, int height)
{
	char	*data;
	int		bpp;
	// int		color;
	int		size_line;
	int		endian;

	if (x < 0 || x >= width || y < 0 || y >= height)
        return 0x000000;  // Devuelve negro si las coordenadas están fuera del rango
    data = mlx_get_data_addr(texture, &bpp, &size_line, &endian);
    if (!data)
        return 0x000000;  // Devuelve negro si falla la obtención de los datos de imagen
    int index = (y * size_line) + (x * (bpp / 8));
    return *(int *)(data + index);
}

void	init_textures(t_game *game)
{
	int size = 64;
	game->north_texture = mlx_xpm_file_to_image(game->window.mlx, NORTH_WALL, &size, &size);
	// printf("%s\n", NORTH_WALL);
	if (game->north_texture == NULL)
	{
		printf("No funciona\n");
		exit (1);
	}
	game->south_texture = mlx_xpm_file_to_image(game->window.mlx, SOUTH_WALL, &size, &size);
	if (game->south_texture == NULL)
	{
		printf("No funciona\n");
		exit (1);
	}
	game->east_texture = mlx_xpm_file_to_image(game->window.mlx, EAST_WALL, &size, &size);
	if (game->east_texture == NULL)
	{
		printf("No funciona\n");
		exit (1);
	}
	game->west_texture = mlx_xpm_file_to_image(game->window.mlx, WEST_WALL, &size, &size);
	if (game->west_texture == NULL)
	{
		printf("No funciona\n");
		exit (1);
	}
	game->door_texture = mlx_xpm_file_to_image(game->window.mlx, DOOR, &size, &size);
	if (game->door_texture == NULL)
	{
		printf("No funciona\n");
		exit (1);
	}
}
