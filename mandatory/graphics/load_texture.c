/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:34:38 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/13 01:15:02 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

static void	*load_image(void *mlx, char *track)
{
	void	*texture;
	int		height;
	int		width;

	texture = mlx_xpm_file_to_image(mlx, track, &width, &height);
	if (!texture)
	{
		ft_printf("Error\nFail to load texture *)\n");
		return (NULL);
	}
	return (texture);
}

void	load_texture(t_game *game)
{
	game->texture.wall = load_image(game->mlx, "textures/asset_wall_3.xpm");
	game->texture.floor = load_image(game->mlx, "textures/asset_floor.xpm");
	game->texture.player = load_image(game->mlx, "textures/asset_player_2.xpm");
	game->texture.collect = load_image(game->mlx,
			"textures/asset_collect_2.xpm");
	game->texture.exit = load_image(game->mlx, "textures/asset_exit_3.xpm");
	game->texture.enemy = load_image(game->mlx, "textures/asset_enemy.xpm");
	game->texture.player_frame = load_image(game->mlx,
			"textures/asset_player_9.xpm");
	game->texture.player_frame2 = load_image(game->mlx,
			"textures/asset_player_10.xpm");
	game->texture.player_frame3 = load_image(game->mlx,
			"textures/asset_player_11.xpm");
	if (!game->texture.wall || !game->texture.floor || !game->texture.collect
		|| !game->texture.player || !game->texture.exit || !game->texture.enemy
		|| !game->texture.player_frame || !game->texture.player_frame2
		|| !game->texture.player_frame3)
	{
		ft_printf("Error\nFail to load all texture *)\n");
		exit(1);
	}
}
