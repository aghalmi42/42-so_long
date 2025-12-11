/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_collectible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:03:38 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/11 20:11:12 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

void	display_collectible(t_game *game)
{
	char	collect[20];
	char	total[20];
	char	display[50];
	int		i;
	int		j;

	i = 7;
	j = 0;
	display[0] = 'I';
	display[1] = 't';
	display[2] = 'e';
	display[3] = 'm';
	display[4] = 's';
	display[5] = ':';
	display[6] = ' ';
	convert(game->player.collect, collect);
	convert(game->map.collectible, total);
	while (collect[j])
		display[i++] = collect[j++];
	display[i++] = '/';
	j = 0;
	while (total[j])
		display[i++] = total[j++];
	display[i] = '\0';
	mlx_string_put(game->mlx, game->win, 10, 40, 0x00FF00, display);
}
