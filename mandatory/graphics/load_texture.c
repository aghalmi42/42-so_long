/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:34:38 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/10 17:19:00 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

//charge map xmp et transforme ca en  imasge mlx
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

//charge les 5 image du jeuu mur sol eetc et stock tt dans game->textuure
void	load_texture(t_game *game)
{
	game->texture.wall = load_image(game->mlx, "textures/asset_wall.xpm");
	game->texture.floor = load_image(game->mlx, "textures/asset_floor.xpm");
	game->texture.player = load_image(game->mlx, "textures/asset_player.xpm");
	game->texture.collect = load_image(game->mlx, "textures/asset_collect.xpm");
	game->texture.exit = load_image(game->mlx, "textures/asset_exit.xpm");

	if (!game->texture.wall || !game->texture.floor || !game->texture.collect
		|| !game->texture.player || !game->texture.exit)
	{
		ft_printf("Error\nFail to load all texture *)\n");
		exit(1);
	}
}