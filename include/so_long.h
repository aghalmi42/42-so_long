/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:18:44 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/21 12:30:53 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
	int				collectible;
	t_pos			exit;
	t_pos			start;
}					t_map;

typedef struct s_player
{
	t_pos			pos;
	int				collect;
	int				move;
}					t_player;

typedef struct s_texture
{
	void			*wall;
	void			*floor;
	void			*player;
	void			*collect;
	void			*exit;
	void			*enemy;
	void			*player_frame;
	void			*player_frame2;
	void			*player_frame3;
}					t_texture;

typedef struct s_enemy
{
	t_pos			pos;
	int				direction;
	struct s_enemy	*next;
}					t_enemy;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_map			map;
	t_player		player;
	t_texture		texture;
	int				win_width;
	int				win_height;
	t_enemy			*monster;
	int				frame;
	int				speed_anim;
}					t_game;

char				**read_file_to_array(char *file_name);
t_map				parsing_map(char *file_name);
int					valid_map(t_map *map);
int					valid_track(t_map *map);
char				*copy_line(char *line, int width);
void				free_part_grid(char **grid, int line);
char				**copy_grid(t_map *map);
void				free_grid(char **grid);
int					init_mlx(t_game *game);
int					init_game(t_game *game, char *file_map);
void				display_map(t_game *game);
void				load_texture(t_game *game);
void				move_player(t_game *game, int x, int y);
int					close_game(t_game *game);
int					press_keypress(int keycode, t_game *game);
void				convert(int n, char *str);
void				display_move(t_game *game);
void				display_collectible(t_game *game);
void				init_enemy(t_game *game);
void				free_enemy(t_enemy *enemy);
void				check_collision_with_enemy(t_game *game);
void				update_enemy(t_game *game);
int					game_loop(t_game *game);
void				*return_player_anim(t_game *game);
void				update_anim(t_game *game);
#endif