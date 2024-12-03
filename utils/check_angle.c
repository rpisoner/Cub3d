/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:03:30 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/29 15:49:44 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_angle(t_game *game)
{
	float	angle_speed;

	angle_speed = 0.03;
	if (game->player.left_rotation)
		game->player.angle -= angle_speed;
	if (game->player.right_rotation)
		game->player.angle += angle_speed;
	if (game->player.angle > 2 * M_PI)
		game->player.angle = 0;
	if (game->player.angle < 0)
		game->player.angle = 2 * M_PI;
}
