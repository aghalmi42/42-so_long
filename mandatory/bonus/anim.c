/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:59:01 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/12 19:13:26 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

void	*return_player_anim(t_game *game)
{
	if ((game->frame / game->speed_anim) % 2 == 0)
		return (game->texture.player);
	else
		return (game->texture.player_frame);
}

void	update_anim(t_game *game)
{
	game->frame++;
	if (game->frame >= 1000)
		game->frame = 0;
}
