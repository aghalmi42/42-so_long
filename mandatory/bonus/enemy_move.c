/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:54:03 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/12 16:55:20 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

static int	enemy_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width)
		return (0);
	if (y < 0 || y >= game->map.height)
		return (0);
	if (game->map.grid[y][x] == '1')
		return (0);
	if (game->map.grid[y][x] == 'C')
		return (0);
	if (game->map.grid[y][x] == 'E')
		return (0);
	return (1);
}

static void	try_move(t_game *game, t_enemy *enemy, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = enemy->pos.x + dx;
	new_y = enemy->pos.y + dy;
	if (enemy_move(game, new_x, new_y))
	{
		enemy->pos.x = new_x;
		enemy->pos.y = new_y;
	}
}

static void	enemy_move_in_map(t_game *game, t_enemy *enemy)
{
	int	dir;

	dir = rand() % 4;
	if (dir == 0)
		try_move(game, enemy, 1, 0);
	else if (dir == 1)
		try_move(game, enemy, 0, 1);
	else if (dir == 2)
		try_move(game, enemy, -1, 0);
	else
		try_move(game, enemy, 0, -1);
}

void	update_enemy(t_game *game)
{
	t_enemy	*now;

	now = game->monster;
	while (now)
	{
		enemy_move_in_map(game, now);
		now = now->next;
	}
}
