/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:03:12 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/20 14:32:56 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	paint_sky_color(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT / 2)
	{
		j = -1;
		while (++j < WIDTH)
			put_pixel(j, i, COLOR_SKY, game);
	}
}

void	paint_floor_color(t_game *game)
{
	int	i;
	int	j;

	i = HEIGHT / 2;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			put_pixel(j, i, game->floor_color, game);
	}
}
