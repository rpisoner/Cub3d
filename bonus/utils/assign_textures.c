/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:36:08 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/09 17:00:24 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
