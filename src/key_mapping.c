/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:06:24 by iortego-          #+#    #+#             */
/*   Updated: 2023/09/09 18:35:13 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	listener(int keycode, t_game	*game)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		move_player(game, (t_coor){.y = -1, .x = 0});
	if (keycode == KEY_S)
		move_player(game, (t_coor){.y = 1, .x = 0});
	if (keycode == KEY_A)
		move_player(game, (t_coor){.y = 0, .x = -1});
	if (keycode == KEY_D)
		move_player(game, (t_coor){.y = 0, .x = 1});
	return (0);
}

int	is_exit(t_game	*game)
{
	if (game->map->map[game->player->pos.y][game->player->pos.x]
		== ITEMS[E])
		exit(0);
	return (0);
}
