/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:56:47 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/29 14:43:15 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_char(t_game *game, int i, int j, int *player_symbols)
{
	char	c;

	c = game->map.map[i][j];
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W' && c != 'E'
		&& c != ' ')
		print_errors(8);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		game->player.x = j * BLOCK_SIZE;
		game->player.y = i * BLOCK_SIZE;
		if (c == 'N')
			game->player.angle = 3 * M_PI / 2;
		else if (c == 'S')
			game->player.angle = M_PI / 2;
		else if (c == 'E')
			game->player.angle = 0;
		else if (c == 'W')
			game->player.angle = M_PI;
		*player_symbols += 1;
	}
}

static void	check_valid_map(t_game *game)
{
	int	i;
	int	j;
	int	player_symbols;

	i = 0;
	player_symbols = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j] != '\0')
		{
			check_char(game, i, j, &player_symbols);
			j++;
		}
		i++;
	}
	if (player_symbols != 1)
		print_errors(7);
	if (!is_map_valid(game->map.map, game->map.y_size))
		print_errors(11);
}

int	longest_line(t_game *game)
{
	int	i;
	int	actual_len;
	int	len;

	i = 0;
	len = 0;
	while (game->map.map[i])
	{
		actual_len = ft_strlen(game->map.map[i]);
		if (actual_len > len)
			len = actual_len;
		i++;
	}
	return (len);
}

static void	copy_map(t_game *game, int i)
{
	int	j;
	int	line_len;

	j = 0;
	while (game->map.raw_file[i])
	{
		game->map.map[j] = game->map.raw_file[i];
		line_len = ft_strlen(game->map.raw_file[i]);
		game->map.map[j][line_len - 1] = '\0';
		i++;
		j++;
	}
	game->map.map[j] = NULL;
	game->map.y_size = j;
	game->map.x_size = longest_line(game);
	print_map(game);
}

void	init_map(t_game *game, int i)
{
	if (game->map.textures_ready == false)
		print_errors(6);
	while (game->map.raw_file[i][0] == '\n')
		i++;
	game->map.map = (char **)malloc((game->map.y_size - i + 1)
			* sizeof(char *));
	if (!game->map.map)
		print_errors(-1);
	copy_map(game, i);
	check_valid_map(game);
}
