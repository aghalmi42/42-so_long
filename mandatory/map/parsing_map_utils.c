/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:22:27 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/09 19:21:30 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

typedef struct s_line
{
	char			*content;
	struct s_line	*next;
}					t_line;

// ajj une ligne a la fin de la lst
t_line	*add_line(t_line *list, char *content)
{
	t_line	*new;
	t_line	*tmp;

	new = malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (list == NULL)
		return (new);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

// count cmbien de maillon dans la lst
int	count_line(t_line *list)
{
	int	count;

	count = 0;
	while (list != NULL)
	{
		count++;
		list = list->next;
	}
	return (count);
}

// free maillon
void	free_list(t_line *list)
{
	t_line	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

// convertir la lst en double tableau
char	**convert_list_to_array(t_line *list, int size)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	while (i < size && list != NULL)
	{
		array[i] = list->content;
		list = list->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
