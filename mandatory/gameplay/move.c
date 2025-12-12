/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:07:06 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/12 19:06:59 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

// verif si nv pose est valide
static int	valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width)
		return (0);
	if (new_y < 0 || new_y >= game->map.height)
		return (0);
	if (game->map.grid[new_y][new_x] == '1')
		return (0);
	return (1);
}

// gere la collect de collectible
static void	collect_collectible(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'C')
	{
		game->map.grid[y][x] = '0';
		game->player.collect++;
		ft_printf("Collect !!! : %d/%d\n", game->player.collect,
			game->map.collectible);
	}
}

// verif si player a win
static void	check_win(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'E')
	{
		if (game->player.collect == game->map.collectible)
		{
			ft_printf("\n WIN ! ;)\n");
			ft_printf("Total move : %d\n", game->player.move);
			close_game(game);
		}
		else
			ft_printf("Collect all collectible first ! %d/%d",
				game->player.collect, game->map.collectible);
	}
}

// deplacer le player
void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player.pos.x + x;
	new_y = game->player.pos.y + y;
	if (!valid_move(game, new_x, new_y))
		return ;
	game->player.pos.x = new_x;
	game->player.pos.y = new_y;
	game->player.move++;
	update_anim(game);
	ft_printf("Move :%d\n", game->player.move);
	collect_collectible(game, new_x, new_y);
	check_win(game, new_x, new_y);
	check_collision_with_enemy(game);
	display_map(game);
	display_move(game);
	display_collectible(game);
}
