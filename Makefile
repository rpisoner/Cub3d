# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 12:23:04 by jolivare          #+#    #+#              #
#    Updated: 2025/02/22 11:52:02 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
BONUS_NAME = bonus/cub3d_bonus

#########################################################################################
# Sources & objects
#########################################################################################
SRC = src/init_map.c inc/get_next_line/get_next_line.c src/errors/print_errors.c src/cub3d.c \
		src/parser/parse_config.c utils/free.c src/visuals/init_window.c src/valid_map.c \
		src/visuals/draw.c src/visuals/draw_floor_ceiling.c utils/collisions.c \
		src/gameplay/movement.c src/gameplay/keyhook.c src/visuals/textures.c \
		src/init_file.c src/init_game.c src/parser/parse_config2.c src/parser/parse.c utils/minimap_utils.c \
		utils/distance.c src/visuals/render.c utils/check_angle.c\
		utils/assign_compass_textures.c src/visuals/compass.c utils/valid_map_utils.c \
		src/parser/parse_colors.c utils/raycast_utils.c 

OBJ = $(SRC:.c=.o)
LIBFT = inc/libft/libft.a
MLX = mlx/libmlx.a

BONUS_SRC = bonus/src/init_map.c bonus/inc/get_next_line/get_next_line.c bonus/src/errors/print_errors.c bonus/src/cub3d.c \
		bonus/src/parser/parse_config.c bonus/utils/free.c bonus/src/visuals/init_window.c bonus/src/valid_map.c \
		bonus/src/visuals/draw.c bonus/src/visuals/draw_floor_ceiling.c bonus/utils/collisions.c \
		bonus/src/gameplay/movement.c bonus/src/gameplay/keyhook.c bonus/src/visuals/textures.c \
		bonus/src/init_file.c bonus/src/init_game.c bonus/src/parser/parse_config2.c bonus/src/parser/parse.c bonus/utils/minimap_utils.c \
		bonus/utils/assign_textures.c bonus/utils/distance.c bonus/src/visuals/render.c bonus/utils/check_angle.c bonus/utils/door_utils.c \
		bonus/utils/assign_compass_textures.c bonus/src/visuals/compass.c bonus/utils/valid_map_utils.c bonus/utils/door_collisions.c \
		bonus/src/parser/parse_colors.c bonus/utils/raycast_utils.c bonus/utils/door_utils2.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

BONUS_LIBFT = bonus/inc/libft/libft.a
BONUS_MLX = bonus/mlx/libmlx.a
BONUS_MLX_FLAGS = -L ./bonus/mlx -lmlx -lXext -lX11 -lm

CC = cc
CFLAGS = -Wall -Wextra -Werror -I inc -I inc/libft -g3
MLX_FLAGS = -L ./mlx -lmlx -lXext -lX11 -lm

#########################################################################################
# Colors
#########################################################################################
DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

#########################################################################################
# Compilation rules
#########################################################################################

all: $(NAME)

$(LIBFT):
	@printf "$(Y)Compiling libft...$(END)\n"
	@$(MAKE) -sC inc/libft/
	@printf "$(G)Libft:\t\tcompiled!📚$(END)\n"

$(MLX):
	@printf "$(Y)Compiling mlx...$(END)\n"
	@$(MAKE) -sC mlx/
	@printf "$(G)Mlx:\tcompiled!🎮$(END)\n"

%.o: %.c
	@printf "$(Y)Compiling $<...$(END)\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(CUT)\r"

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@printf "$(Y)Compiling Cub3D...$(END)\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(MLX) $(LIBFT)
	@printf "$(G)Cub3D\tcompiled!$(END)\n"

# Regla para compilar el bonus
bonus: $(BONUS_NAME)

$(BONUS_LIBFT):
	@printf "$(Y)Compiling bonus libft...$(END)\n"
	@$(MAKE) -sC bonus/inc/libft/
	@printf "$(G)Bonus Libft:\tcompiled!📚$(END)\n"

$(BONUS_MLX):
	@printf "$(Y)Compiling bonus mlx...$(END)\n"
	@$(MAKE) -sC bonus/mlx/
	@printf "$(G)Bonus Mlx:\tcompiled!🎮$(END)\n"

$(BONUS_NAME): $(BONUS_OBJ) $(BONUS_LIBFT) $(BONUS_MLX)
	@printf "$(Y)Compiling Cub3D Bonus...$(END)\n"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME) $(BONUS_MLX_FLAGS) $(BONUS_MLX) $(BONUS_LIBFT)
	@printf "$(G)Cub3D Bonus\tcompiled!✨$(END)\n"

clean:
	@$(MAKE) clean -sC inc/libft/
	@printf "$(Y)Libft$(END)$(R) .o files removed$(END)\n"
	@printf "$(Y)MLX messages:$(END)\n"
	@$(MAKE) clean -sC mlx/
	@printf "$(Y)MLX$(END)$(R) .o files removed$(END)\n"
	@rm -f $(OBJ)
	@printf "$(R)All .o files removed$(END)\n"

fclean: clean bclean
	@$(MAKE) fclean -sC inc/libft/
	@printf "$(R)Executable libft removed$(END)\n"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@printf "$(R)Executable file removed$(END)\n"

bclean:
	@rm -f $(BONUS_OBJ)
	@printf "$(R)Bonus object files removed!$(END)\n"
	@$(MAKE) -sC bonus/inc/libft/ clean
	@printf "$(Y)Libft$(END)$(R) .o files removed$(END)\n"
	@printf "$(Y)MLX messages:$(END)\n"
	@$(MAKE) -sC bonus/mlx/ clean
	@printf "$(Y)MLX$(END)$(R) .o files removed$(END)\n"

bfclean: bclean
	@$(MAKE) -sC bonus/inc/libft/ fclean
	@printf "$(R)Executable libft removed$(END)\n"
	@rm -f $(BONUS_NAME)
	@printf "$(R)Bonus executable removed!$(END)\n"

bre: bfclean bonus

c: all clean

re: fclean all

r: all clean
	@clear
	@./$(NAME) maps/map2.cub

v: all clean
	@clear
	@valgrind --leak-check=full ./$(NAME) maps/map2.cub

.PHONY: all clean fclean bonus bclean bfclean bre re c v