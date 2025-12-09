/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:39:47 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/09 16:49:18 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

typedef struct s_line
{
	char			*content;
	struct s_line	*next;
}					t_line;

t_line	*add_line(t_line *list, char *content);
int		count_line(t_line *list);
void	free_list(t_line *list);
char	**convert_list_to_array(t_line list, int size);

// check si extension est .ber
static int	check_extension(char *file_name)
{
	int	len;

	if (!file_name)
		return (0);
	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	if (ft_strncmp(file_name + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

// pour oouvrir le fichieer
static int	open_file(char *file_name)
{
	int	fd;

	if (!check_extension(file_name))
	{
		ft_printf("error\ninvalid file extension *)\n");
		return (-1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_printf("error\nunable to open file *)\n");
	return (fd);
}

// on trim le \n et on add la line
static t_line	*processus_of_line(t_line *list, char *line)
{
	char	*after_strtrim;

	after_strtrim = ft_strtrim(line, "\n");
	free(line);
	if (!after_strtrim)
		return (NULL);
	list = add_line(list, after_strtrim);
	if (!list)
		free(after_strtrim);
	return (list);
}

// lis tt les line
static t_line	*read_line(int fd)
{
	t_line	*list;
	char	*line;

	list = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = processus_of_line(list, line);
		if (!list)
		{
			close(fd);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	return (list);
}

// converti .ber en string
char	**read_file_to_array(char *file_name)
{
	t_line	*list;
	char	**array;
	int		fd;

	fd = open_file(file_name);
	if (fd < 0)
		return (NULL);
	list = read_line(fd);
	close(fd);
	if (!list || count_line(list) == 0)
	{
		free_list(list);
		return (NULL);
	}
	array = convert_list_to_array(*list, count_line(list));
	free_list(list);
	return (array);
}
