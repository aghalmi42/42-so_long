/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:01:57 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/13 00:56:56 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

int	game_loop(t_game *game)
{
	static int	count = 0;

	count++;
	if (count >= 10000)
	{
		update_enemy(game);
		check_collision_with_enemy(game);
		display_map(game);
		count = 0;
	}
	return (0);
}
