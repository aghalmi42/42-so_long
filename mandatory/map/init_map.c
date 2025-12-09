/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:05:32 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/09 21:00:15 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	map_dimension(t_map *map)
{
	int	height;

	height = 0;
	while (map->grid[height] != NULL)
		height++;
	map->height = height;
	map->width = ft_strlen(map->grid[0]);
}

static void	check_char(t_map *map, int x, int y)
{
	char	c;

	c = map->grid[y][x];
	if (c == 'P')
	{
		map->start.x = x;
		map->start.y = y;
	}
	else if (c == 'E')
	{
		map->exit.x = x;
		map->exit.y = y;
	}
	else if (c == 'C')
		map->collectible++;
}

static void	scan_line(t_map *map, int y)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		check_char(map, x, y);
		x++;
	}
}

static void	find_element_of_map(t_map *map)
{
	int	y;

	y = 0;
	map->collectible = 0;
	while (y < map->height)
	{
		scan_line(map, y);
		y++;
	}
}

// pars la dim map et composant map
t_map	parsing_map(char *file_name)
{
	t_map	map;

	map.grid = read_file_to_array(file_name);
	if (map.grid == NULL)
		return (map);
	map_dimension(&map);
	find_element_of_map(&map);
	return (map);
}
