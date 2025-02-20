/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:55:04 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/20 19:43:51 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_line(t_game *game, float ray_angle)
{
	float	cos_angle;
	float	sin_angle;
	float	dist;

	cos_angle = cos(ray_angle);
	sin_angle = sin(ray_angle);
	game->vars.ray_x = game->player.x;
	game->vars.ray_y = game->player.y;
	game->vars.delta_x = fabsf(1 / cos_angle);
	game->vars.delta_y = fabsf(1 / sin_angle);
	choose_ray_direction(game, cos_angle, sin_angle);
	dda(game, cos_angle, sin_angle);
	dist = fixed_distance(game->player.x, game->player.y, game);
	if (dist > INT_MAX)
		return ;
	assign_orientation(game, game->vars.side, cos_angle, sin_angle);
	render(game, dist);
}
