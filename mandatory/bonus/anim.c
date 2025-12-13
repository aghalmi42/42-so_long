/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:59:01 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/12 23:51:18 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

void	*return_player_anim(t_game *game)
{
	int	frame_index;

	frame_index = (game->frame / game->speed_anim) % 4;
	if (frame_index == 0)
		return (game->texture.player);
	else if (frame_index == 1)
		return (game->texture.player_frame);
	else if (frame_index == 2)
		return (game->texture.player_frame2);
	else
		return (game->texture.player_frame3);
}

void	update_anim(t_game *game)
{
	game->frame++;
	if (game->frame >= 1000)
		game->frame = 0;
}
