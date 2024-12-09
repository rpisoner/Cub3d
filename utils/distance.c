/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:56:44 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/09 14:35:01 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_distance(float x1, float y1, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = game->vars.ray_x - x1;
	delta_y = game->vars.ray_y - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

int check_ray_distance(t_game *game)
{
	if (game->vars.ray_x < 0 || game->vars.ray_x > (float)INT_MAX)
		return (1);
	if (game->vars.ray_y < 0 || game->vars.ray_y > (float)INT_MAX)
		return (1);
	return (0);
}
