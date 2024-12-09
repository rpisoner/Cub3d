/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:29:49 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/09 16:56:29 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	exit_game(t_game *game)
{
	free(game->door);
	mlx_destroy_image(game->window.mlx, game->south_compass);
	mlx_destroy_image(game->window.mlx, game->south_east_compass);
	mlx_destroy_image(game->window.mlx, game->south_west_compass);
	mlx_destroy_image(game->window.mlx, game->north_compass);
	mlx_destroy_image(game->window.mlx, game->north_east_compass);
	mlx_destroy_image(game->window.mlx, game->north_west_compass);
	mlx_destroy_image(game->window.mlx, game->east_compass);
	mlx_destroy_image(game->window.mlx, game->west_compass);
	mlx_destroy_image(game->window.mlx, game->north_texture);
	mlx_destroy_image(game->window.mlx, game->south_texture);
	mlx_destroy_image(game->window.mlx, game->west_texture);
	mlx_destroy_image(game->window.mlx, game->east_texture);
	mlx_destroy_image(game->window.mlx, game->door_texture);
	mlx_destroy_window(game->window.mlx, game->window.window);
	exit (0);
}

int	mouse_detect(int x, int y, t_game *game)
{
	float	angle_speed;	

	angle_speed = 0.02;
	(void)y;
	if (x > WIDTH / 2)
		game->player.angle += angle_speed;
	else if (x < WIDTH / 2)
		game->player.angle -= angle_speed;
	mlx_mouse_move(game->window.mlx, game->window.window,
		WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	init_window(&game);
	parse(&game, argc, argv);
	init_compass_textures(&game);
	mlx_mouse_hide(game.window.mlx, game.window.window);
	mlx_mouse_move(game.window.mlx, game.window.window, WIDTH / 2, HEIGHT / 2);
	mlx_hook(game.window.window, 6, 1L << 6, mouse_detect, &game);
	mlx_hook(game.window.window, 2, 1L << 0, key_press, &game);
	mlx_hook(game.window.window, 3, 1L << 1, key_release, &game.player);
	mlx_hook(game.window.window, 17, 0, exit_game, &game);
	mlx_loop_hook(game.window.mlx, draw_loop, &game);
	mlx_loop(game.window.mlx);
}
