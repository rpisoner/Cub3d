/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:10:12 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/26 10:56:25 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	load_north_texture(t_game *game, int i, int *size)
{
	char	**aux;
	char	*real_dir;

	aux = ft_split(game->map.raw_file[i], ' ');
	if (aux[1][ft_strlen(aux[1]) - 1] == '\n')
	{
		real_dir = ft_substr(aux[1], 0, ft_strlen(aux[1]) - 1);
		game->north_texture = mlx_xpm_file_to_image(game->window.mlx, real_dir,
				size, size);
		free(real_dir);
	}
	else
		game->north_texture = mlx_xpm_file_to_image(game->window.mlx, aux[1],
				size, size);
	free_str(aux);
	if (game->north_texture == NULL)
		print_errors(2);
}

static void	load_south_texture(t_game *game, int i, int *size)
{
	char	**aux;
	char	*real_dir;

	aux = ft_split(game->map.raw_file[i], ' ');
	if (aux[1][ft_strlen(aux[1]) - 1] == '\n')
	{
		real_dir = ft_substr(aux[1], 0, ft_strlen(aux[1]) - 1);
		game->south_texture = mlx_xpm_file_to_image(game->window.mlx, real_dir,
				size, size);
		free(real_dir);
	}
	else
		game->south_texture = mlx_xpm_file_to_image(game->window.mlx, aux[1],
				size, size);
	free_str(aux);
	if (game->south_texture == NULL)
		print_errors(3);
}

static void	load_west_texture(t_game *game, int i, int *size)
{
	char	**aux;
	char	*real_dir;

	aux = ft_split(game->map.raw_file[i], ' ');
	if (aux[1][ft_strlen(aux[1]) - 1] == '\n')
	{
		real_dir = ft_substr(aux[1], 0, ft_strlen(aux[1]) - 1);
		game->west_texture = mlx_xpm_file_to_image(game->window.mlx, real_dir,
				size, size);
		free(real_dir);
	}
	else
		game->west_texture = mlx_xpm_file_to_image(game->window.mlx, aux[1],
				size, size);
	free_str(aux);
	if (game->west_texture == NULL)
		print_errors(4);
}

static void	load_east_texture(t_game *game, int i, int *size)
{
	char	**aux;
	char	*real_dir;

	aux = ft_split(game->map.raw_file[i], ' ');
	if (aux[1][ft_strlen(aux[1]) - 1] == '\n')
	{
		real_dir = ft_substr(aux[1], 0, ft_strlen(aux[1]) - 1);
		game->east_texture = mlx_xpm_file_to_image(game->window.mlx, real_dir,
				size, size);
		free(real_dir);
	}
	else
		game->east_texture = mlx_xpm_file_to_image(game->window.mlx, aux[1],
				size, size);
	free_str(aux);
	if (game->east_texture == NULL)
		print_errors(5);
}

void	parse_config(t_game *game)
{
	int		i;
	int		size;

	i = 0;
	size = 64;
	while (game->map.textures_ready == false && game->map.raw_file[i])
	{
		if (ft_strncmp(game->map.raw_file[i], "NO", 2) == 0)
			load_north_texture(game, i, &size);
		else if (ft_strncmp(game->map.raw_file[i], "SO", 2) == 0)
			load_south_texture(game, i, &size);
		else if (ft_strncmp(game->map.raw_file[i], "WE", 2) == 0)
			load_west_texture(game, i, &size);
		else if (ft_strncmp(game->map.raw_file[i], "EA", 2) == 0)
			load_east_texture(game, i, &size);
		else if (ft_strncmp(game->map.raw_file[i], "F", 1) == 0)
			load_floor_color(game, i);
		else if (ft_strncmp(game->map.raw_file[i], "C", 1) == 0)
			load_ceiling_color(game, i);
		if (textures_ready(game))
			game->map.textures_ready = true;
		i++;
	}
	init_map(game, i);
}
