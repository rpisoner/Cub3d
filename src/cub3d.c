/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:29:49 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/25 15:37:05 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_game game;
	(void)argc;
	(void)argv;
	init_window(&game);
	mlx_hook(game.window.window, 2, 1L<<0, key_press, &game.player);
	mlx_hook(game.window.window, 3, 1L<<1, key_release, &game.player);
	mlx_loop_hook(game.window.mlx, draw_loop, &game);
	mlx_loop(game.window.mlx);
	// init_map(&game, argv[1]);
}