/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:56:47 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/29 10:56:32 by rpisoner         ###   ########.fr       */
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

// static void	check_line(t_game *game, int i)
// {
// 	size_t	j;

// 	j = 0;
// 	if (i == 0 || game->map.map[i + 1] == NULL)
// 	{
// 		while (game->map.map[i][j] == 1 || game->map.map[i][j] == ' ')
// 			j++;
// 		if (j != ft_strlen(game->map.map[i]) - 1)
// 			print_errors(11);
// 	}
// 	else
// 	{
		
// 	}
// }

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
		//check_line(game, i); Mapa rodeado de muros
		while (game->map.map[i][j] != '\0')
		{
			check_char(game, i, j, &player_symbols);
			j++;
		}
		i++;
	}
	if (player_symbols != 1)
		print_errors(7);
}

static void	copy_map(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map.raw_file[i])
	{
		game->map.map[j] = game->map.raw_file[i];
		game->map.map[j][ft_strlen(game->map.raw_file[i]) - 1] = '\0';
		i++;
		j++;
	}
	game->map.map[j] = NULL;
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

// char	**get_map(t_game *game)
// {
// 	char	**map;

// 	map = malloc(sizeof(char *) * 11);
// 	map[0] = "1111111111111111111111111111111";
// 	map[1] = "1000000000000000D00000000000001";
// 	map[2] = "1000000000000000111000000000001";
// 	map[3] = "1000001000000010000000000000001";
// 	map[4] = "1000000000000011111111111111111";
// 	map[5] = "1000000100000000000000000000001";
// 	map[6] = "1000010000000000000000000000001";
// 	map[7] = "100000000N000011100001110000001";
// 	map[8] = "1000000000000011100000000000001";
// 	map[9] = "1111111111111111111111111111111";
// 	map[10] = NULL;
// 	game->map.y_size = 11;
// 	game->map.x_size = ft_strlen(map[0]);
// 	return (map);
// }
