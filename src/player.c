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
	self->pos.x = -1;
	self->pos.y = -1;
	self->next = self->pos;
	while (map.map[coor.y] != NULL && self->pos.x == -1)
	{
		coor.x = 0;
		while (map.map[coor.y][coor.x] != '\n' && self->pos.x == -1) 
		{
			if (map.map[coor.y][coor.x] == ITEMS[P])
				self->pos = coor;
			coor.x++;
		}
		coor.y++;
	}
	self->img_s = img;
	return (self); 
}
