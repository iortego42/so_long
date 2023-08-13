/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:33:12 by iortego-          #+#    #+#             */
/*   Updated: 2023/08/13 18:29:01 by iortego-         ###   ########.fr       */
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

t_bool	is_valid_char(t_map	*map)
{
	t_coor	coor;

	coor.y = 0;
	while (map->map[coor.y] != NULL)
	{
		coor.x = 0;
		while (map->map[coor.y][coor.x] != '\n')
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
		while (map->map[coor.y][coor.x] != '\n')
		{
			if (coor.x == 0 || coor.x == map->dim.x - 1
				|| coor.y == 0 || coor.y == map->dim.y - 1)
				if (map->map[coor.y][coor.x] != ITEMS[W])
					return (FALSE);
			coor.x++;
		}
		coor.y++;
	}
	return (TRUE);
}

t_bool	is_one_player_exit(t_map	*map)
{
	t_coor	coor;
	int		players;
	int		exit;

	players = 0;
	exit = 0;
	coor.y = 0;
	while (map->map[coor.y])
	{
		coor.x = 0;
		while (map->map[coor.y][coor.x] != '\n')
		{
			if (map->map[coor.y][coor.x] == ITEMS[P])
				players++;
			if (map->map[coor.y][coor.x] == ITEMS[E])
				exit++;
			if (players > 1 || exit > 1)
				return (FALSE);
			coor.x++;
		}
		coor.y++;
	}
	return (TRUE);
}

t_err_code	parse_map(t_map	*map)
{
	if (is_sym(map) == FALSE)
		return (EC_NOT_SYM);
	if (is_valid_char(map) == FALSE)
		return (EC_INVALID_CHAR);
	if (is_walled(map) == FALSE)
		return (EC_WALLED);
	if (is_one_player_exit(map) == FALSE)
		return (EC_NO_PLAYER);
	return (OK);
}
