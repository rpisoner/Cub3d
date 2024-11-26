/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:35:45 by rpisoner          #+#    #+#             */
/*   Updated: 2024/11/26 13:27:42 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
	{
		printf("%s\n", game->map.map[i]);
		i++;
	}

}
