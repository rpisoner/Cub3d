/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:29:49 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/26 18:52:27 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	exit_game(void)
{
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game game;
	(void)argc;
	(void)argv;
	init_window(&game);
	mlx_mouse_move(game.window.mlx, game.window.window, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_hide(game.window.mlx, game.window.window);
	mlx_hook(game.window.window, 2, 1L<<0, key_press, &game.player);
	mlx_hook(game.window.window, 3, 1L<<1, key_release, &game.player);
	mlx_hook(game.window.window, 17, 0, exit_game, &game);
	mlx_loop_hook(game.window.mlx, draw_loop, &game);
	mlx_loop(game.window.mlx);
	// init_map(&game, argv[1]);
}