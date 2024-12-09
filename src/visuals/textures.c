/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:06:10 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/09 16:56:24 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_texture_color(void *texture, t_game *game, int width, int height)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		index;

	if (game->texture_x < 0 || game->texture_x >= width || game->texture_y < 0 \
		|| game->texture_y >= height)
		return (0x000000);
	data = mlx_get_data_addr(texture, &bpp, &size_line, &endian);
	if (!data)
		return (0x000000);
	index = (game->texture_y * size_line) + (game->texture_x * (bpp / 8));
	return (*(int *)(data + index));
}

void	init_compass_textures(t_game *game)
{
	int	width;
	int	height;

	width = 256;
	height = 128;
	init_north_compass(game, width, height);
	init_south_compass(game, width, height);
	init_west_compass(game, width, height);
	init_east_compass(game, width, height);
}
