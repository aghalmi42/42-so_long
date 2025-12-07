/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:42:19 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/07 18:47:52 by aghalmi          ###   ########.fr       */
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
