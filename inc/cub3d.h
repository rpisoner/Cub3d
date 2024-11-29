/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:19:57 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/29 10:53:37 by rpisoner         ###   ########.fr       */
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
# define NORTH_WALL "textures/north.xpm"
# define SOUTH_WALL "textures/south.xpm"
# define WEST_WALL "textures/west.xpm"
# define EAST_WALL "textures/east.xpm"
# define DOOR "textures/door.xpm"
# define _USE_MATH_DEFINES
# define COLOR_SKY 0x87CEEB
# define COLOR_FLOOR 0x8B4513
# define COLOR_NORTH 0xFF0000
# define COLOR_SOUTH 0x00FF00
# define COLOR_EAST  0x0000FF
# define COLOR_WEST  0xFFFF00
# define COLOR_DOOR  0x800080
# define MINIMAP_BG_COLOR 0x808080
# define MINIMAP_BG_WIDTH 300
# define MINIMAP_BG_HEIGHT 200
# define MINIMAP_SCALE 0.3
# define MINIMAP_BLOCK_SIZE 20
# define WIDTH 1500
# define HEIGHT 720
# define BLOCK_SIZE 64
# define TEXTURE_WIDTH 64
# define W 119
# define A 97
# define S 115
# define D 100
# define E 101
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define M_PI		3.14159265358979323846	/* pi */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

typedef struct s_window
{
	void	*mlx;
	void	*window;
	void	*image;
}	t_window;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	key_door;
	bool	key_door_pressed;

	bool	left_rotation;
	bool	right_rotation;
}	t_player;

typedef struct s_map
{
	char	**raw_file;
	char	**map;
	bool	textures_ready;
	int		y_size;
	int		x_size;
}	t_map;

typedef struct s_game
{
	t_map		map;
	t_window	window;
	t_player	player;
	void		*north_texture;
	void		*south_texture;
	void		*east_texture;
	void		*west_texture;
	void		*door_texture;
	int			floor_color;
	int			ceiling_color;
	int			mini_x;
	int			mini_y;
	int			size_line;
	int			orientation;
	char		*data;
	int			bpp;
	int			endian;
	bool		door_open;
}	t_game;

char	*get_next_line(int fd);

//MAP PARSING
void	load_floor_color(t_game *game, int i);
void	load_ceiling_color(t_game *game, int i);
void	init_file(t_game *game, char *file);
void	init_map(t_game *game, int i);
void	init_file(t_game *game, char *file);
bool	textures_ready(t_game *game);
void	parse_config(t_game *game);
void	parse(t_game *game, int argc, char **argv);

//Initializers
void	init_game(t_game *game);
void	init_window(t_game *game);

int		exit_game(void);

int		key_press(int keycode, t_player *player, t_game *game);
int		key_release(int keycode, t_player *player);
void	move_player(t_game *game);

void	init_textures(t_game *game);

void	put_pixel(int x, int y, int color, t_game *game);
int		draw_loop(t_game *game);
void	draw_minimap_background(t_game *game);
int		get_texture_color(void *texture, int x, int y, int width, int height);
void	draw_square(int x, int y, int size, int color, t_game *game);
void	draw_map(t_game *game);
void	draw_line(t_player *player, t_game *game, float start_x, int i);
void	paint_sky_color(t_game *game);
void	paint_floor_color(t_game *game);
bool	touch(float px, float py, t_game *game);

//COLLISIONS
int		is_wall_up(t_game *game, int speed, float cos_angle, float sin_angle);
int		is_wall_down(t_game *game, int speed, float cos_angle, float sin_angle);
int		is_wall_left(t_game *game, int speed, float cos_angle, float sin_angle);
int		is_wall_right(t_game *game, int speed, float cos_angle,
			float sin_angle);
int		is_door(t_game *game, int speed, float cos_angle, float sin_angle);

void	print_errors(int code);

//DEV UTILS
void	print_map(t_game *game);

void	free_str(char **str);

#endif