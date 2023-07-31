/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:41:35 by iortego-          #+#    #+#             */
/*   Updated: 2023/07/23 16:02:14 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*player_constructor(t_map	map, t_img *img) 
{
	t_player	*self;
	t_coor		coor;

	coor.y = 0;
	if (img == NULL || img->img == NULL 
			|| map.map == NULL || map.map[0] == NULL || map.map[0][0] == 0)
		return (NULL);
	self = (t_player *)malloc(sizeof(t_player));
	if (!self)
		return (NULL);
	self->pos.x = -1;
	self->pos.y = -1;
	while (map.map[coor.y] != NULL && self->pos.x == -1)
	{
		coor.x = 0;
		while (map.map[coor.y][coor.x] != '\n' && self->pos.x == -1) 
		{
			if (map.map[coor.y][coor.x] == ITEMS[P])
				self->pos = (t_coor){.y = coor.y, .x = coor.x};
			coor.x++;
		}
		coor.y++;
	}
	self->img_s = img;
	return (self); 
}

t_bool	is_reacheble(t_coor	pos, t_coor	next_pos)
{
	if ((pos.x == next_pos.x + 1 || pos.x == next_pos.x - 1) && pos.y == next_pos.y)
		return (TRUE);
	else if ((pos.x == next_pos.x + 1 || pos.x == next_pos.x - 1) && pos.y == next_pos.y)
		return (TRUE);
	return (FALSE);
}

void	print_moves(int	moves)
{
	char	*movestr;

	ft_putstr_fd("[!] Moves: ", 1);
	movestr = ft_itoa(moves);
	ft_putstr_fd(movestr, 1);
	free(movestr);
	movestr = NULL;
	ft_putstr_fd("\r", 1);
}

t_bool	check_move(t_game	*game, t_coor	next_pos)
{
	t_item	position;
	
	position =  game->map->map[next_pos.y][next_pos.x];

	if (position == ITEMS[W] || !is_reacheble(game->player->pos, next_pos))
		return (FALSE);
	else if (position == ITEMS[E] && game->collectionable != 0)
		return (FALSE);
	return (TRUE);
}

void	move_player(t_game	*game, t_coor	move)
{
	t_coor	next_pos;

	next_pos.x = game->player->pos.x + move.x;
	next_pos.y = game->player->pos.y + move.y;
	if (check_move(game, next_pos))
	{
		if (game->map->map[next_pos.y][next_pos.x] == ITEMS[C])
		{
			game->collectionable--;
			game->map->map[next_pos.y][next_pos.x] = ITEMS[F];
		}
		game->map->map[game->player->pos.y][game->player->pos.x] = ITEMS[F]; 
		game->player->pos = next_pos;
		game->map->map[game->player->pos.y][game->player->pos.x] = ITEMS[P]; 
		game->player->move_counter++;
		
		print_moves(game->player->move_counter);
	}
}