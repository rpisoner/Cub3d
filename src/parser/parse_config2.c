/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:27:36 by rpisoner          #+#    #+#             */
/*   Updated: 2024/11/24 17:52:25 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	load_floor_color(t_game *game, int i)
{
	char	**aux;

	aux = ft_split(game->map.raw_file[i], ' ');
	game->floor_color = ft_atoi(aux[1]);
	free_str(aux);
}

void	load_ceiling_color(t_game *game, int i)
{
	char	**aux;

	aux = ft_split(game->map.raw_file[i], ' ');
	game->ceiling_color = ft_atoi(aux[1]);
	free_str(aux);
}

bool	textures_ready(t_game *game)
{
	return (game->north_texture && game->east_texture && game->west_texture
		&& game->south_texture && game->floor_color && game->ceiling_color);
}
