/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:52:33 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/04 17:44:07 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_compass(t_game *game)
{
	void	*active_img;
	float	angle;

	angle = game->player.angle * (180 / M_PI);
	if (angle < 0)
		angle += 360;
	if (angle >= 337.5 || angle < 22.5)
		active_img = game->east_compass;
	else if (angle >= 22.5 && angle < 67.5)
		active_img = game->south_east_compass;
	else if (angle >= 67.5 && angle < 112.5)
		active_img = game->south_compass;
	else if (angle >= 112.5 && angle < 157.5)
		active_img = game->south_west_compass;
	else if (angle >= 157.5 && angle < 202.5)
		active_img = game->west_compass;
	else if (angle >= 202.5 && angle < 247.5)
		active_img = game->north_west_compass;
	else if (angle >= 247.5 && angle < 292.5)
		active_img = game->north_compass;
	else
		active_img = game->north_east_compass;
	mlx_put_image_to_window(game->window.mlx, game->window.window, active_img, 675, 500);
}
