/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:50:15 by rpisoner          #+#    #+#             */
/*   Updated: 2024/11/29 13:05:04 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_out_of_bounds(int x, int y, int rows, char **map)
{
	return (x < 0 || y < 0 || x >= rows || y >= (int)ft_strlen(map[x]));
}

// Function to check if rows are surrounded by walls
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
			return (0); // Row not surrounded by walls
		i++;
	}
	return (1);
}

// Recursive flood-fill function
int flood_fill(char **map, int x, int y, int rows, int **visited)
{
	if (is_out_of_bounds(x, y, rows, map)
		|| map[x][y] == ' ' || map[x][y] == '\0')
		return (0); // Reached outside the map boundary or invalid space
	if (map[x][y] == '1' || visited[x][y])
		return (1); // Hit a wall or already visited
    visited[x][y] = 1; // Mark the current cell as visited
    // Explore in all four directions
	return (flood_fill(map, x - 1, y, rows, visited)
		&& flood_fill(map, x + 1, y, rows, visited)
		&& flood_fill(map, x, y - 1, rows, visited)
		&& flood_fill(map, x, y + 1, rows, visited));
}

// Function to validate the map
int	is_map_valid(char **map, int rows)
{
	int	**visited;
	int	row_length;
	int	i;
	int	j;
	int	k;
	
    // Check if all rows are surrounded by walls
	if (!are_rows_valid(map, rows))
	{
		printf("HERE\n");
		return (0); // Horizontal boundary violation
	}

	i = 0;
	visited = malloc(rows * sizeof(int *));
    // Allocate a visited matrix
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
				if (!flood_fill(map, i, j, rows, visited)) {
					// Free memory and return invalid
					k = 0;
					while (k < rows)
					{
						free(visited[k]);
						k++;
					}
					free(visited);
					printf("AQUÍ\n");
					return (0); // Map is not valid
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
	return (1); // Map is valid
}
