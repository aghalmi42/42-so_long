/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:42:19 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/08 20:04:02 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	map_is_rectangul(t_map *map)
{
	int	y;
	int	len;

	y = 0;
	while (y < map->height)
	{
		len = ft_strlen(map->grid[y]);
		if (len != map->width)
			return (0);
		y++;
	}
	return (1);
}

static int	check_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != 1)
			return (0);
		if (map->grid[map->height - 1][x] != 1)
			return (0);
		x++;
	}
	while (y < map->height)
	{
		if (map->grid[0][y] != 1)
			return (0);
		if (map->grid[map->width - 1][y] != 1)
			return (0);
		y++;
	}
	return (1);
}

static int	check_valid_element(t_map *map)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->grid[y][x];
			if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static void	count_element(t_map *map, int *player_count, int *exit_count)
{
	int		x;
	int		y;
	char	c;

	player_count = 0;
	exit_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->grid[y][x];
			if (c == 'P')
				(*player_count)++;
			if (c == 'E')
				(*exit_count)++;
			x++;
		}
		y++;
	}
}

int	valid_map(t_map *map)
{
	int	player_count;
	int	exit_count;

	if (!map_is_rectangul(map))
	{
		ft_printf("Error\nMap is not rectangular\n");
		return (0);
	}
	if (!check_wall(map))
	{
		ft_printf("Error\nMap is not surrounded by wall\n");
		return (0);
	}
	if (!check_valid_element(map))
	{
		ft_printf("Error\nMap contain invalid character\n");
		return (0);
	}
	count_element(map, &player_count, &exit_count);
	if (player_count != 1 || exit_count != 1 || map->collectible < 1)
	{
		ft_printf("Error\nInvalid number of the element\n");
		return (0);
	}
	return (1);
}
