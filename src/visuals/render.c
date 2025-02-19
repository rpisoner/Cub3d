/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:48:52 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/19 02:15:46 by jolivare         ###   ########.fr       */
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
			color = get_texture_color(game->west_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		else if (game->orientation == 4)
			color = get_texture_color(game->east_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		else if (game->is_door == 1)
			color = get_texture_color(game->door_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		put_pixel(game->vars.index, start_y, color, game);
		start_y++;
	}
}

void	render(t_game *game, float dist, float cos_angle, float sin_angle)
{
	int		start_y;
	int		end;
	float	wall_pos;

	game->vars.center_y = HEIGHT / 2;
	game->vars.projected_height = (int)((BLOCK_SIZE / dist) * (WIDTH / 2));
	start_y = game->vars.center_y - game->vars.projected_height / 2;
	end = game->vars.center_y + game->vars.projected_height / 2;
	if (game->is_door)
	{
		if (fabsf(cos_angle) > fabsf(sin_angle))
			wall_pos = game->vars.ray_y;
		else
			wall_pos = game->vars.ray_x;
	}
	else
	{
		if (game->orientation == 1 || game->orientation == 2)
			wall_pos = game->vars.ray_x;
		else
			wall_pos = game->vars.ray_y;	
	}
	wall_pos = fmod(wall_pos, BLOCK_SIZE);
	game->texture_x = (int)(wall_pos / BLOCK_SIZE * TEXTURE_WIDTH);
	if (game->orientation == 4)
		game->texture_x = TEXTURE_WIDTH - 1 - game->texture_x;
	render_raycast(game, start_y, end);
}
