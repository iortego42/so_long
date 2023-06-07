/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:33:12 by iortego-          #+#    #+#             */
/*   Updated: 2023/06/07 20:18:03 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <so_long.h>

int	get_line_lenght(char *line)
{
	int	len;

	len = 0;
	while (line[len] != '\n' && line[len] != 0)
		len++;
	return (len);
}
t_bool	is_item(t_map	*map)
{
	t_coor	coor;

	coor.y = 0;
	while (map->map[coor.y] != NULL) 
	{
		coor.x = 0;
		while (map->map[coor.y][coor.x] != 0)
		{
			if (ft_strchr(ITEMS, map->map[coor.y][coor.x]) == NULL)
				return (FALSE);
			coor.x++;
		}
		coor.y++;
	}
	return (TRUE); 
}

t_bool	is_walled(t_map *map)
{
	t_coor	coor;

	coor.y = 0;
	while (map->map[coor.y] != NULL) 
	{
		coor.x = 0;
		while (map->map[coor.y][coor.x] != 0)
		{
			if (coor.x == 0 || coor.x == map->dim.x - 1 ||
				coor.y == 0 || coor.y == map->dim.y - 1)
				if (map->map[coor.y][coor.x] != ITEMS[W])
					return (FALSE);
			coor.x++;
		}
		coor.y++;
	}
	return (TRUE);
}

t_bool	parse_map(t_map	*map)
{
	if (is_sym(map) == FALSE)
		return (FALSE);
	if (is_item(map) == FALSE)
		return (FALSE);
	if (is_walled(map) == FALSE)
		return (FALSE);
	return (TRUE);
}
