/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:58:12 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/12 19:12:21 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../minilibx-linux/mlx.h"

int	press_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}

// clique sur croix rouge ferme le jeu
int	close_game(t_game *game)
{
	int	i;

	i = 0;
	free_enemy(game->monster);
	if (game->texture.wall)
		mlx_destroy_image(game->mlx, game->texture.wall);
	if (game->texture.floor)
		mlx_destroy_image(game->mlx, game->texture.floor);
	if (game->texture.player)
		mlx_destroy_image(game->mlx, game->texture.player);
	if (game->texture.exit)
		mlx_destroy_image(game->mlx, game->texture.exit);
	if (game->texture.collect)
		mlx_destroy_image(game->mlx, game->texture.collect);
	if (game->texture.enemy)
		mlx_destroy_image(game->mlx, game->texture.enemy);
	if (game->texture.player_frame)
		mlx_destroy_image(game->mlx, game->texture.player_frame);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	while (game->map.grid && game->map.grid[i])
	{
		free(game->map.grid[i]);
		i++;
	}
	if (game->map.grid)
		free(game->map.grid);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

	srand(time(NULL));
	if (ac != 2 || !init_game(&game, av[1]))
	{
		ft_printf("Missing map.ber or fail game init *)\n");
		return (1);
	}
	ft_printf("Game init OK !\n");
	ft_printf("Window %dx%d pixel\n", game.win_width, game.win_height);
	load_texture(&game);
	ft_printf("Texture is load !");
	display_map(&game);
	ft_printf("Map OK !\nGame start !\nControl W/S/A/D or ARROW KEYS\n");
	ft_printf("ESC for quit\n");
	mlx_key_hook(game.win, press_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
