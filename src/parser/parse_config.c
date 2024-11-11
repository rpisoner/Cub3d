/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:10:12 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/11 14:54:01 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	parse_config(t_game *game)
{
	int 	i;
	char	**aux;
	char	*real_dir;
	int		size;

	i = -1;
	size = 64;
	while (game->map.raw_file[++i])
	{
		if (ft_strncmp(game->map.raw_file[i], "NO", 2) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			real_dir = ft_substr(aux[1], 0, ft_strlen(aux[1]) - 1);
			printf("%s\n", real_dir);
			game->north_texture = mlx_xpm_file_to_image(game->window.mlx, real_dir, &size, &size);
			// printf("Aqui\n");
			if (game->north_texture == NULL)
			{
				printf ("Error al cargar a textura norte\n");
				exit (1);
			}
			free_str(aux);
		}
		else if (ft_strncmp(game->map.raw_file[i], "SO", 2) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->south_texture = mlx_xpm_file_to_image(game->window.mlx, aux[1], &size, &size);
			if (game->south_texture == NULL)
			{
				printf ("Error al cargar a textura sur\n");
				exit (1);
			}
			free_str(aux);
		}
		else if (ft_strncmp(game->map.raw_file[i], "WE", 2) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->west_texture = mlx_xpm_file_to_image(game->window.mlx, aux[1], &size, &size);
			if (game->west_texture == NULL)
			{
				printf ("Error al cargar a textura oeste\n");
				exit (1);
			}
			free_str(aux);
		}
		else if (ft_strncmp(game->map.raw_file[i], "EA", 2) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->east_texture = mlx_xpm_file_to_image(game->window.mlx, aux[1], &size, &size);
			if (game->east_texture == NULL)
			{
				printf ("Error al cargar a textura este\n");
				exit (1);
			}
			free_str(aux);
		}
		else if (ft_strncmp(game->map.raw_file[i], "F", 1) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->floor_color = ft_atoi(aux[1]);
			free_str(aux);
		}
		else if (ft_strncmp(game->map.raw_file[i], "C", 1) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->ceiling_color = ft_atoi(aux[1]);
			free_str(aux);
		}
	}
}
