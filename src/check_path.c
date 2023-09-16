/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:17:02 by iortego-          #+#    #+#             */
/*   Updated: 2023/09/16 11:10:34 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*copy_map(t_map map)
{
	t_map	*copy;

	copy = (t_map *)malloc(sizeof(t_map));
	if (copy == NULL)
		return (NULL);
	copy->map = ft_matrixcpy(map.map);
	if (!copy->map)
		return (free(copy), NULL);
	copy->items = map.items;
	copy->exit = map.exit;
	copy->dim = map.dim;
	return (copy);
}

/*void print_checkmap(t_map map) {
	int a = 0;
	usleep(100000);
	ft_putstr_fd("\033c",1);
	while (map.map[a] != NULL)
		ft_putstr_fd(map.map[a++], 1);
}*/

t_bool	check_map(t_map *map, t_coor pos, t_bool *exit_is_reach)
{
	if (map->map[pos.y][pos.x] == ITEMS[W])
		return (FALSE);
	if (map->map[pos.y][pos.x] == ITEMS[C])
	{
		map->map[pos.y][pos.x] = ITEMS[F];
		map->items--;
	}
	if (map->map[pos.y][pos.x] == ITEMS[E])
		*exit_is_reach = TRUE;
	if (map->map[pos.y][pos.x] == 'G')
		return (FALSE);
	map->map[pos.y][pos.x] = 'G';
	check_map(map, (t_coor){.y = pos.y + 1, .x = pos.x}, exit_is_reach);
	check_map(map, (t_coor){.y = pos.y - 1, .x = pos.x}, exit_is_reach);
	check_map(map, (t_coor){.y = pos.y, .x = pos.x + 1}, exit_is_reach);
	check_map(map, (t_coor){.y = pos.y, .x = pos.x - 1}, exit_is_reach);
	if (map->items == 0 && *exit_is_reach == TRUE)
		return (TRUE);
	return (FALSE);
}
