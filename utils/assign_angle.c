/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:33:43 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/29 17:47:37 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	assing_initial_angle(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while(game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'N')
				game->player.angle = 3 * M_PI / 2;
			else if (game->map.map[i][j] == 'S')
				game->player.angle = M_PI / 2;
			else if (game->map.map[i][j] == 'E')
				game->player.angle =  0;
			else if (game->map.map[i][j] == 'W')
				game->player.angle =  M_PI;
		}
	}
}