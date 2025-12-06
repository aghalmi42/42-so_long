/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:18:44 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/06 20:32:30 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

t_line	*add_line(t_line *list, char *content);
int		count_line(t_line *list);
void	free_list(t_line *list);
char	**convert_list_to_array(t_line list, int size);
char	**read_file_to_array(char *file_name);

#endif