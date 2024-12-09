# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 12:23:04 by jolivare          #+#    #+#              #
#    Updated: 2024/12/09 16:11:32 by rpisoner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

#########################################################################################
# Sources & objects
#########################################################################################
SRC = src/init_map.c inc/get_next_line/get_next_line.c src/errors/print_errors.c src/cub3d.c \
		src/parser/parse_config.c utils/free.c src/visuals/init_window.c src/valid_map.c \
		src/visuals/draw.c src/visuals/draw_floor_ceiling.c utils/collisions.c \
		src/gameplay/movement.c src/gameplay/keyhook.c src/visuals/textures.c \
		src/init_file.c src/init_game.c src/parser/parse_config2.c src/parser/parse.c utils/dev_utils.c \
		utils/assign_textures.c utils/distance.c src/visuals/render.c utils/check_angle.c utils/door_utils.c \
		utils/assign_compass_textures.c src/visuals/compass.c utils/valid_map_utils.c

OBJ = $(SRC:.c=.o)
LIBFT = inc/libft/libft.a
MLX = mlx/libmlx.a
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
	@$(MAKE) -C mlx/
	@printf "$(G)Mlx:\tcompiled!🎮$(END)\n"

%.o: %.c
	@printf "$(Y)Compiling $<...$(END)\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(CUT)\r"

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@printf "$(Y)Compiling Cub3D...$(END)\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(MLX) $(LIBFT)
	@printf "$(G)Cub3D\tcompiled!$(END)\n"

clean:
	@make clean -sC inc/libft/
	@printf "$(Y)Libft$(END)$(R) .o files removed$(END)\n"
	@printf "$(Y)MLX messages:$(END)\n"
	@make clean -sC mlx/
	@printf "$(Y)MLX$(END)$(R) .o files removed$(END)\n"
	@rm -f $(OBJ)
	@printf "$(R)All .o files removed$(END)\n"


fclean: clean
	@make fclean -sC inc/libft/
	@printf "$(R)Executable libft removed$(END)\n"
	@rm -f $(NAME)
	@printf "$(R)Executable file removed$(END)\n"

c: all clean

re: fclean all

r: all clean
	@clear
	@./$(NAME) maps/map.cub

v: all clean
	@clear
	@valgrind --leak-check=full ./$(NAME) maps/map.cub
.PHONY: all clean fclean re c