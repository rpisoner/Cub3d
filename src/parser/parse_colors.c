/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:59:20 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/19 16:58:21 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void assign_floor_color(t_game *game)
{
	char	**aux;

	aux = ft_split(game->floor_color, ',');
	check_color_format(aux);
	
}