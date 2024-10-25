/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:19:57 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/25 17:46:28 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# define _USE_MATH_DEFINES
# define WIDTH 1280
# define HEIGHT 720
# define BLOCK_SIZE 64
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

typedef struct	s_window
{
	void	*mlx;
	void	*window;
	void	*image;
} t_window;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotation;
	bool	right_rotation;
} t_player;

typedef struct s_map
{
	char	**raw_file;
	char	**map;
	int		y_size;
} t_map;


typedef struct s_game
{
	t_map		map;
	t_window	window;
	t_player	player;
	char		*north_texture;
	char		*south_texture;
	char		*east_texture;
	char		*west_texture;
	int			floor_color;
	int			ceiling_color;
	int			size_line;
	char		*data;
	int			bpp;
	int			endian;
} t_game;

char	*get_next_line(int fd);

void	init_map(t_game *game, char *file);
void	init_window(t_game *game);
void	init_player(t_player *player);
char 	**get_map(void);

int		key_press(int keycode, t_player *player);
int		key_release(int keycode, t_player *player);
void	move_player(t_player *player);

void	put_pixel(int x, int y, int color, t_game *game);
int		draw_loop(t_game *game);
void	draw_square(int x, int y, int size, int color, t_game *game);
void	draw_map(t_game *game);
void	draw_line(t_player *player, t_game *game, float start_x, int i);
bool	touch(float px, float py, t_game *game);

void	print_errors(int code);

void	free_str(char **str);

void	parse_config(t_game *game);

#endif