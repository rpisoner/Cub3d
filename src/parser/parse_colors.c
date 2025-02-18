/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:59:20 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/19 00:00:57 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	do_and_check_atoi(int *rgb, char **aux)
{
	rgb[0] = ft_atoi(aux[0]);
	if (rgb[0] < 0 || rgb[0] > 255)
	{
		printf("Error:\n\tFirst number is invalid\n");
		exit (1);
	}
	rgb[1] = ft_atoi(aux[1]);
	if (rgb[1] < 0 || rgb[1] > 255)
	{
		printf("Error:\n\tSecond number is invalid\n");
		exit (1);
	}
	rgb[2] = ft_atoi(aux[2]);
	if (rgb[2] < 0 || rgb[2] > 255)
	{
		printf("Error:\n\tThird number is invalid\n");
		exit (1);
	}
}

void	assign_floor_color(t_game *game)
{
	char	**aux;
	int		*rgb;
	int		i;

	i = -1;
	aux = ft_split(game->floor_str, ',');
	check_color_format(aux);
	rgb = malloc(sizeof(int *) * 3);
	do_and_check_atoi(rgb, aux);
	game->floor_color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	while (aux[++i])
		free (aux[i]);
	free (aux);
	free (rgb);
}

void	assign_ceiling_color(t_game *game)
{
	char	**aux;
	int		*rgb;
	int		i;

	i = -1;
	aux = ft_split(game->ceiling_str, ',');
	check_color_format(aux);
	rgb = malloc(sizeof(int *) * 3);
	do_and_check_atoi(rgb, aux);
	game->ceiling_color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	while (aux[++i])
		free (aux[i]);
	free (aux);
	free (rgb);
}
