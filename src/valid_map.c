/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:50:15 by rpisoner          #+#    #+#             */
/*   Updated: 2024/12/03 11:01:05 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_out_of_bounds(int x, int y, int rows, char **map)
{
	return (x < 0 || y < 0 || x >= rows || y >= (int)ft_strlen(map[x]));
}

int	are_rows_valid(char **map, int rows)
{
	int	i;
	int	row_length;

	i = 0;
	while (i < rows)
	{
		row_length = ft_strlen(map[i]);
		if ((map[i][0] != ' ' && map[i][0] != '1')
			|| map[i][row_length - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	flood_fill(char **map, int x, int y, int rows, int **visited)
{
	if (is_out_of_bounds(x, y, rows, map)
		|| map[x][y] == ' ' || map[x][y] == '\0')
		return (0);
	if (map[x][y] == '1' || visited[x][y])
		return (1);
	visited[x][y] = 1;
	return (flood_fill(map, x - 1, y, rows, visited)
		&& flood_fill(map, x + 1, y, rows, visited)
		&& flood_fill(map, x, y - 1, rows, visited)
		&& flood_fill(map, x, y + 1, rows, visited));
}

int	is_map_valid(char **map, int rows)
{
	int	**visited;
	int	row_length;
	int	i;
	int	j;
	int	k;

	if (!are_rows_valid(map, rows))
	{
		printf("HERE\n");
		return (0);
	}
	i = 0;
	visited = malloc(rows * sizeof(int *));
	while (i < rows)
	{
		row_length = ft_strlen(map[i]);
		visited[i] = ft_calloc(row_length, sizeof(int));
		i++;
	}
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if ((map[i][j] == '0' || ft_strchr("NSEW", map[i][j]))
				&& !visited[i][j])
			{
				if (!flood_fill(map, i, j, rows, visited))
				{
					k = 0;
					while (k < rows)
					{
						free(visited[k]);
						k++;
					}
					free(visited);
					printf("AQUÍ\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	return (1);
}
