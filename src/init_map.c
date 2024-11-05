/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:56:47 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/05 12:12:17 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	copy_file(t_game *game, char *file)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(file, O_RDONLY);
	while (++i < game->map.y_size)
		game->map.raw_file[i] = get_next_line(fd);
	close(fd);
}

void	init_map(t_game *game, char *file)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		free(line);
		print_errors(1);
	}
	height = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		height++;
	}
	close(fd);
	game->map.y_size = height;
	game->map.raw_file = (char **)malloc(sizeof(char *) * (height + 1));
	copy_file(game, file);
	parse_config(game);
}

char	**get_map(t_game *game)
{
	char	**map;
	
	map = malloc(sizeof(char *) * 11);
	map[0] = "1111111111111111111111111111111";
	map[1] = "1000000000000000D00000000000001";
	map[2] = "1000000000000000111000000000001";
	map[3] = "1000001000000010000000000000001";
	map[4] = "1000000000000011111111111111111";
	map[5] = "1000000100000000000000000000001";
	map[6] = "1000010000000000000000000000001";
	map[7] = "100000000N000011100001110000001";
	map[8] = "1000000000000011100000000000001";
	map[9] = "1111111111111111111111111111111";
	map[10] = NULL;
	game->map.y_size = 11;
	game->map.x_size = ft_strlen(map[0]);
	return (map);
}
