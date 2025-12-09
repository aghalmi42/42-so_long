/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_track_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:19:45 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/09 16:46:31 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// copy une line pour la grid en flood
char	*copy_line(char *line, int width)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = malloc(sizeof(char) * (width + 1));
	if (!new_line)
		return (NULL);
	while (i < width)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

//free part de grid //en appel de f
void	free_part_grid(char **grid, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

// copy de grid pour flood pour modif direct sur copy
char	**copy_grid(t_map *map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	while (i < map->height)
	{
		copy[i] = copy_line(map->grid[i], map->width);
		if (!copy[i])
		{
			free_part_grid(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

//free notre grid
void	free_grid(char **grid)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
