/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:55:35 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/11 20:11:29 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

void	convert(int n, char *str)
{
	int	i;
	int	tmp;
	int	len;

	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	len = 0;
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	str[len] = '\0';
	i = len - 1;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

void	display_move(t_game *game)
{
	char	move[20];
	char	display[50];
	int		i;
	int		j;

	i = 7;
	j = 0;
	display[0] = 'M';
	display[1] = 'o';
	display[2] = 'v';
	display[3] = 'e';
	display[4] = 's';
	display[5] = ':';
	display[6] = ' ';
	convert(game->player.move, move);
	while (move[j])
	{
		display[i] = move[j];
		i++;
		j++;
	}
	display[i] = '\0';
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFF00, display);
}
