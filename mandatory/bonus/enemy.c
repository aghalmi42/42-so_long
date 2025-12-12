/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:46:13 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/12 15:52:29 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

static t_enemy	*new_enemy(t_enemy *list, int x, int y)
{
	t_enemy	*new;
	t_enemy	*now;

	new = malloc(sizeof(t_enemy));
	if (!new)
		return (list);
	new->pos.x = x;
	new->pos.y = y;
	new->direction = 1;
	new->next = NULL;
	if (!list)
		return (new);
	now = list;
	while (now->next)
		now = now->next;
	now->next = new;
	return (list);
}

void	init_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->monster = NULL;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'M')
			{
				game->monster = new_enemy(game->monster, x, y);
				game->map.grid[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	free_enemy(t_enemy *enemy)
{
	t_enemy	*tmp;

	while (enemy)
	{
		tmp = enemy;
		enemy = enemy->next;
		free(tmp);
	}
}

void	check_collision_with_enemy(t_game *game)
{
	t_enemy	*now;

	now = game->monster;
	while (now)
	{
		if (now->pos.x == game->player.pos.x
			&& now->pos.y == game->player.pos.y)
		{
			ft_printf("\n GAME OVER !!\n");
			ft_printf("Your are dead by enemy *)\n");
			close_game(game);
		}
		now = now->next;
	}
}
