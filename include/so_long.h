/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:18:44 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/06 21:38:29 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "../../ft_printf/ft_printf.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	**read_file_to_array(char *file_name);

#endif