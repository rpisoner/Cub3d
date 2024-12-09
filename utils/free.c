/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:57:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/12/09 12:35:32 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free (str);
}

void	free_door(t_game *game)
{
	free(game->door);
}
