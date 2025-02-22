/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:30:24 by rpisoner          #+#    #+#             */
/*   Updated: 2025/02/19 00:03:15 by jolivare         ###   ########.fr       */
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
	game->map.raw_file[i] = NULL;
	close(fd);
}

static void	check_line(char *line, int fd)
{
	if (line == NULL)
	{
		close(fd);
		free(line);
		print_errors(1);
	}
}

void	init_file(t_game *game, char *file)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	check_line(line, fd);
	height = 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	game->map.y_size = height;
	game->map.raw_file = (char **)malloc(sizeof(char *) * (height + 1));
	copy_file(game, file);
	parse_config(game);
	assign_floor_color(game);
	assign_ceiling_color(game);
}
