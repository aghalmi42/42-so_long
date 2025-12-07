/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:18:44 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/07 18:35:47 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../ft_printf/ft_printf.h"
# include "../../libft/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectible;
	t_pos	exit;
	t_pos	start;
}			t_map;

char		**read_file_to_array(char *file_name);
t_map		parsing_map(char *file_name);

#endif