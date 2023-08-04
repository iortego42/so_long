/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:17:02 by iortego-          #+#    #+#             */
/*   Updated: 2023/06/08 17:38:28 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


t_bool  check_map(t_map *map, t_coor pos, t_bool *exit_is_reach)
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
    check_map(map, (t_coor){.y = pos.y + 1, .x = pos.x}, exit_is_reach);
    check_map(map, (t_coor){.y = pos.y - 1, .x = pos.x}, exit_is_reach);
    check_map(map, (t_coor){.y = pos.y, .x = pos.x + 1}, exit_is_reach);
    check_map(map, (t_coor){.y = pos.y, .x = pos.x - 1}, exit_is_reach);
    if (map->items == 0 && exit_is_reach)
        return (TRUE);
    return (FALSE);
}