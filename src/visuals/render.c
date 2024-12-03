/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:48:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/03 11:59:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	render_raycast(t_game *game, int start_y, int end)
{
	int	color;

	while (start_y < end)
	{
		game->texture_y = (start_y - game->vars.center_y + \
			game->vars.projected_height / 2) * \
			TEXTURE_WIDTH / game->vars.projected_height;
		if (game->orientation == 1)
			color = get_texture_color(game->north_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		else if (game->orientation == 2)
			color = get_texture_color(game->south_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		else if (game->orientation == 3)
			color = get_texture_color(game->east_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		else if (game->orientation == 4)
			color = get_texture_color(game->west_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		else if (game->orientation == 5)
			color = get_texture_color(game->door_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		put_pixel(game->vars.index, start_y, color, game);
		start_y++;
	}
}

void	render(t_game *game, float dist)
{
	int	start_y;
	int	end;

	game->vars.center_y = HEIGHT / 2;
	game->vars.projected_height = (int)((BLOCK_SIZE / dist) * (WIDTH / 2));
	start_y = game->vars.center_y - game->vars.projected_height / 2;
	end = game->vars.center_y + game->vars.projected_height / 2;
	if (game->orientation == 1 || game->orientation == 2)
		game->texture_x = (int)game->vars.ray_x % TEXTURE_WIDTH;
	else
		game->texture_x = (int)game->vars.ray_y % TEXTURE_WIDTH;
	render_raycast(game, start_y, end);
}
