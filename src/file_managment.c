/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_managment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:33:29 by iortego-          #+#    #+#             */
/*   Updated: 2023/06/07 19:21:00 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include "so_long.h"

t_bool	is_sym(t_map *map)
{
	int	prevlen;
	int	len;
	int	index;

	len = get_line_lenght(map->map[index]);
	while (map->map[index] != NULL)
	{
		prevlen = len;
		len = get_line_lenght(map->map[index]);
		if (len != prevlen)
			return (FALSE);
		index++;
	}
	map->dim.x = len;
	map->dim.y = index;
	return	(TRUE);
}

t_map	*get_map(char *path) 
{
	int		fd;
	int		index;
	t_map	*map;
	char	*line;

	index = 0;
	map = (t_map *) malloc(sizeof(t_map));
	map->map = NULL;
	fd = open(path, O_RDONLY);
	if	(fd > 0)
	{
		while (line != NULL)
		{
			line = get_next_line(fd);
			map->map = (char	**)realloc(map->map, sizeof(char	**) * (index + 1));
			map->map[index] = line;
			index++;
		}
		map->map[index] = NULL;
		map->dim.y = index;
		close(fd);
	}
	return (map);
}
