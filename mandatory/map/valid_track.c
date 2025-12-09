/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_track.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:05:35 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/09 16:45:16 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	flood_fill(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'X')
		return ;
	grid[y][x] = 'X';
	flood_fill(grid, x + 1, y, map);
	flood_fill(grid, x - 1, y, map);
	flood_fill(grid, x, y + 1, map);
	flood_fill(grid, x, y - 1, map);
}

static int	count_collectible(t_map *map, char **grid)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'C' && grid[y][x] == 'X')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static int	possibility_to_exit(t_map *map, char **grid)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'E' && grid[y][x] == 'X')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_flood_result(t_map *map, char **grid)
{
	int	accessible;

	accessible = count_collectible(map, grid);
	if (accessible != map->collectible)
	{
		ft_printf("Error\nSome collectible are not accessible *)\n");
		return (0);
	}
	if (!possibility_to_exit(map, grid))
	{
		ft_printf("Error\nExit is not accessible *)\n");
		return (0);
	}
	return (1);
}

// check map is valid & copy de map en flood
int	valid_track(t_map *map)
{
	char	**grid_copy;
	int		result;

	grid_copy = copy_grid(map);
	if (!grid_copy)
	{
		ft_printf("Error\nfail memory allocation *)\n");
		return (0);
	}
	flood_fill(grid_copy, map->start.x, map->start.y, map);
	result = check_flood_result(map, grid_copy);
	free_grid(grid_copy);
	return (result);
}
