/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:05:35 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/08 20:11:05 by aghalmi          ###   ########.fr       */
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
