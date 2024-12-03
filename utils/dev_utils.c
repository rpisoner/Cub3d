/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:35:45 by rpisoner          #+#    #+#             */
/*   Updated: 2024/11/29 15:49:25 by jolivare         ###   ########.fr       */
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
