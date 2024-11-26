/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:30:24 by rpisoner          #+#    #+#             */
/*   Updated: 2024/11/24 18:51:11 by rpisoner         ###   ########.fr       */
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

void	init_file(t_game *game, char *file)
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
