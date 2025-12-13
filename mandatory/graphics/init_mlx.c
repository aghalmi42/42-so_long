/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:12:37 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/13 01:14:55 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nFail init MLX *)\n");
		return (0);
	}
	game->win_width = game->map.width * TILE_SIZE;
	game->win_height = game->map.height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height,
			"so_long");
	if (!game->win)
	{
		ft_printf("Error\nFail window creation *)\n");
		return (0);
	}
	return (1);
}

int	init_game(t_game *game, char *file_map)
{
	game->map = parsing_map(file_map);
	if (!game->map.grid)
		return (0);
	if (!valid_map(&game->map))
		return (0);
	if (!valid_track(&game->map))
		return (0);
	game->player.pos = game->map.start;
	game->player.collect = 0;
	game->player.move = 0;
	game->frame = 0;
	game->speed_anim = 1;
	init_enemy(game);
	if (!init_mlx(game))
		return (0);
	return (1);
}
