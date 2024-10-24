/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:19:57 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/24 16:40:23 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

typedef struct s_map
{
	char	**raw_file;
	char	**map;
	int		pos_x;
	int		pos_y;
	int		y_size;
	char	player_dir;
} t_map;


typedef struct s_game
{
	t_map	map;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		floor_color;
	int		ceiling_color;
} t_game;

char	*get_next_line(int fd);

void	init_map(t_game *game, char *file);

void	print_errors(int code);

void	free_str(char **str);

void	parse_config(t_game *game);

#endif