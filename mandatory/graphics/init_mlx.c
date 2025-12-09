/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:12:37 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/09 19:38:03 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

// intialisewr mlx et cree fenetre de 64 pixel suur 64
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

//pars la map .ber et la valid ety veerifie le chemin et init le player et mlx
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
	if (!init_mlx(game))
		return (0);
	return (1);
}
