/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:19:57 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/22 10:06:41 by rpisoner         ###   ########.fr       */
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
# include <limits.h>
# define COMPASS_NORTH "textures/compass/compass_north.xpm"
# define COMPASS_SOUTH "textures/compass/compass_south.xpm"
# define COMPASS_WEST "textures/compass/compass_west.xpm"
# define COMPASS_EAST "textures/compass/compass_east.xpm"
# define COMPASS_NORTH_WEST "textures/compass/compass_northwest.xpm"
# define COMPASS_NORTH_EAST "textures/compass/compass_northeast.xpm"
# define COMPASS_SOUTH_WEST "textures/compass/compass_southwest.xpm"
# define COMPASS_SOUTH_EAST "textures/compass/compass_southeast.xpm"
# define COLOR_SKY 0x87CEEB
# define COLOR_FLOOR 0x8B4513
# define MINIMAP_BG_COLOR 0x808080
# define MINIMAP_BG_WIDTH 300
# define MINIMAP_BG_HEIGHT 200
# define MINIMAP_SCALE 0.3
# define MINIMAP_BLOCK_SIZE 20
# define WIDTH 1680
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
# define M_PI 3.14159265358979323846	/* pi */
# define MAX_DISTANCE_SQ 100.0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_window
{
	void	*mlx;
	void	*window;
	void	*image;
}	t_window;

typedef struct s_vars
{
	float	ray_x;
	float	ray_y;
	float	projected_height;
	int		center_y;
	int		index;
	int		color;
	float	delta_x;
	float	delta_y;
	int		step_x;
	int		step_y;
	float	side_x;
	float	side_y;
	int		side;
	float	wall_x;
	float	wall_y;
}	t_vars;

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
	t_vars		vars;
	void		*north_texture;
	void		*south_texture;
	void		*east_texture;
	void		*west_texture;
	void		*north_compass;
	void		*south_compass;
	void		*west_compass;
	void		*east_compass;
	void		*north_west_compass;
	void		*north_east_compass;
	void		*south_west_compass;
	void		*south_east_compass;
	char		*floor_str;
	char		*ceiling_str;
	int			mini_x;
	int			mini_y;
	int			size_line;
	int			orientation;
	char		*data;
	int			bpp;
	int			endian;
	int			texture_x;
	int			texture_y;
	int			speed;
	int			floor_color;
	int			ceiling_color;
	int			limit_steps;
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
int		is_map_valid(char **map, int rows);
int		is_out_of_bounds(int x, int y, int rows, char **map);

//Initializers
void	init_game(t_game *game);
void	init_window(t_game *game);

int		exit_game(t_game *game);

int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_player *player);
void	move_player(t_game *game);

void	init_compass_textures(t_game *game);

void	put_pixel(int x, int y, int color, t_game *game);
int		draw_loop(t_game *game);
void	draw_minimap_background(t_game *game);
int		get_texture_color(void *texture, t_game *game, int width, int height);
void	init_north_compass(t_game *game, int width, int height);
void	init_south_compass(t_game *game, int width, int height);
void	init_west_compass(t_game *game, int width, int height);
void	init_east_compass(t_game *game, int width, int height);
void	render(t_game *game, float dist);
void	draw_minimap(t_game *game);
void	assign_floor_color(t_game *game);
void	assign_ceiling_color(t_game *game);
void	draw_compass(t_game *game);
void	draw_line(t_game *game, float start_x);
void	paint_sky_color(t_game *game);
void	paint_floor_color(t_game *game);
float	distance(float x, float y);
float	fixed_distance(float x1, float y1, t_game *game);
void	assign_orientation(t_game *game, int side, \
		float cos_angle, float sin_angle);
void	dda(t_game *game, float cos_angle, float sin_angle);
void	choose_ray_direction(t_game *game, float cos_angle, float sin_angle);

//COLLISIONS
int		is_wall_up(t_game *game, int speed, float cos_angle, float sin_angle);
int		is_wall_down(t_game *game, int speed, \
		float cos_angle, float sin_angle);
int		is_wall_left(t_game *game, int speed, \
		float cos_angle, float sin_angle);
int		is_wall_right(t_game *game, int speed, \
		float cos_angle, float sin_angle);
void	assign_e_w(t_game *game, float cos_angle);
void	assign_n_s(t_game *game, float sin_angle);

void	check_angle(t_game *game);
void	print_errors(int code);
void	check_color_format(char **str);

//FREE STUFF
void	free_str(char **str);
void	free_matrix(int **matrix);

#endif