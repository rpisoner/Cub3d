/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:50:15 by rpisoner          #+#    #+#             */
/*   Updated: 2024/12/09 16:35:05 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

int	flood_fill(char **map, t_coords coords, int rows, int **visited)
{
	if (is_out_of_bounds(coords.x, coords.y, rows, map)
		|| map[coords.x][coords.y] == ' ' || map[coords.x][coords.y] == '\0')
		return (0);
	if (map[coords.x][coords.y] == '1' || visited[coords.x][coords.y])
		return (1);
	visited[coords.x][coords.y] = 1;

	return (flood_fill(map, (t_coords){coords.x - 1, coords.y}, rows, visited)
		&& flood_fill(map, (t_coords){coords.x + 1, coords.y}, rows, visited)
		&& flood_fill(map, (t_coords){coords.x, coords.y - 1}, rows, visited)
		&& flood_fill(map, (t_coords){coords.x, coords.y + 1}, rows, visited));
}

static int	**allocate_visited(int rows, char **map)
{
	int	**visited;
	int	row_length;
	int	i;

	visited = malloc((rows + 1) * sizeof(int *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		row_length = ft_strlen(map[i]);
		visited[i] = ft_calloc(row_length, sizeof(int));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		i++;
	}
	visited[i] = NULL;
	return (visited);
}

static int	process_map(char **map, int rows, int **visited)
{
	t_coords	coords;

	coords.x = 0;
	while (coords.x < rows)
	{
		coords.y = 0;
		while ((size_t)coords.y < ft_strlen(map[coords.x]))
		{
			if ((map[coords.x][coords.y] == '0'
				|| ft_strchr("NSEW", map[coords.x][coords.y]))
				&& !visited[coords.x][coords.y])
			{
				if (!flood_fill(map, coords, rows, visited))
					return (0);
			}
			coords.y++;
		}
		coords.x++;
	}
	return (1);
}

int	is_map_valid(char **map, int rows)
{
	int	**visited;

	if (!are_rows_valid(map, rows))
		return (0);
	visited = allocate_visited(rows, map);
	if (!visited)
		return (0);
	if (!process_map(map, rows, visited))
	{
		free_matrix(visited);
		return (0);
	}
	free_matrix(visited);
	return (1);
}
