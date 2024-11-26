/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:11:29 by rpisoner          #+#    #+#             */
/*   Updated: 2024/11/24 19:23:00 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_extension_cub(char *file)
{
	int	i;

	i = -1;
	while (file[++i])
		;
	i--;
	if (!file[i] || file[i] != 'b')
		return (1);
	i--;
	if (!file[i] || file[i] != 'u')
		return (1);
	i--;
	if (!file[i] || file[i] != 'c')
		return (1);
	i--;
	if (!file[i] || file[i] != '.')
		return (1);
	return (0);
}

void	parse(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		print_errors(10);
	if (check_extension_cub(argv[1]))
		print_errors(9);
	init_file(game, argv[1]);
}
