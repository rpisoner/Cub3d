/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:08:06 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/19 11:50:07 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(int x, int y, int size, int color, t_game *game)
{
	int	i;

	i = -1;
	while (++i < size)
		put_pixel(x + i, y, color, game);
	i = -1;
	while (++i < size)
		put_pixel(x, y + i, color, game);
	i = -1;
	while (++i < size)
		put_pixel(x + size, y + i, color, game);
	i = -1;
	while (++i < size)
		put_pixel(x + i, y + size, color, game);
}

void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel(x, y, 0, game);
	}
}

int	draw_loop(t_game *game)
{
	float	fraction;
	float	start_x;

	move_player(game);
	clear_image(game);
	paint_sky_color(game);
	paint_floor_color(game);
	fraction = M_PI / 3 / WIDTH;
	start_x = game->player.angle - M_PI / 6;
	game->vars.index = 0;
	while (game->vars.index < WIDTH)
	{
		draw_line(game, start_x);
		start_x += fraction;
		game->vars.index++;
	}
	draw_minimap(game);
	mlx_put_image_to_window(game->window.mlx, \
		game->window.window, game->window.image, 0, 0);
	draw_compass(game);
	return (0);
}

void	init_window(t_game *game)
{
	game->window.mlx = mlx_init();
	game->window.window = mlx_new_window(game->window.mlx, \
		WIDTH, HEIGHT, "jogo");
	game->window.image = mlx_new_image(game->window.mlx, \
		WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->window.image, \
		&game->bpp, &game->size_line, &game->endian);
	mlx_put_image_to_window(game->window.mlx, \
		game->window.window, game->window.image, 0, 0);
}
