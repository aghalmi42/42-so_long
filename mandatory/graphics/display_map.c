/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:21:10 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/13 01:14:48 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

static void	display_tile(t_game *game, int x, int y)
{
	char	c;
	int		pixel_y;
	int		pixel_x;

	c = game->map.grid[y][x];
	pixel_x = x * TILE_SIZE;
	pixel_y = y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->texture.floor, pixel_x,
		pixel_y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->texture.wall,
			pixel_x, pixel_y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->texture.collect,
			pixel_x, pixel_y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->texture.exit,
			pixel_x, pixel_y);
}

static void	display_enemy(t_game *game)
{
	t_enemy	*enemy;

	enemy = game->monster;
	while (enemy)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->texture.enemy,
			enemy->pos.x * TILE_SIZE, enemy->pos.y * TILE_SIZE);
		enemy = enemy->next;
	}
}

static void	display_entity(t_game *game)
{
	display_enemy(game);
	mlx_put_image_to_window(game->mlx, game->win, return_player_anim(game),
		game->player.pos.x * TILE_SIZE, game->player.pos.y * TILE_SIZE);
	display_move(game);
	display_collectible(game);
}

void	display_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			display_tile(game, x, y);
			x++;
		}
		y++;
	}
	display_entity(game);
}
