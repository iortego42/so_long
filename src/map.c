/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:40:00 by iortego-          #+#    #+#             */
/*   Updated: 2023/09/09 17:03:39 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_floor(t_map map, t_img floor, t_mlx *mlx)
{
	t_coor	coor;

	coor.y = 0;
	while (map.map[coor.y] != NULL)
	{
		coor.x = 0;
		while (map.map[coor.y][coor.x] != '\n' && map.map[coor.y][coor.x] != 0)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, floor.img,
				coor.x * IMG_WIDTH, coor.y * IMG_HEIGHT);
			coor.x++;
		}
		coor.y++;
	}
}

void	print_static(t_map map, t_img *images, t_mlx *mlx)
{
	t_coor	coor;

	coor.y = 0;
	while (map.map[coor.y] != NULL)
	{
		coor.x = 0;
		while (map.map[coor.y][coor.x] != '\n' && map.map[coor.y][coor.x] != 0)
		{
			if (map.map[coor.y][coor.x] == ITEMS[W])
				mlx_put_image_to_window(mlx->mlx, mlx->win, images[W].img,
					coor.x * IMG_WIDTH, coor.y * IMG_HEIGHT);
			else if (map.map[coor.y][coor.x] == ITEMS[C])
				mlx_put_image_to_window(mlx->mlx, mlx->win, images[C].img,
					coor.x * IMG_WIDTH, coor.y * IMG_HEIGHT);
			else if (map.map[coor.y][coor.x] == ITEMS[E])
				mlx_put_image_to_window(mlx->mlx, mlx->win, images[E].img,
					coor.x * IMG_WIDTH, coor.y * IMG_HEIGHT);
			coor.x++;
		}
		coor.y++;
	}
}

int	get_items(t_map	map)
{
	t_coor	coor;

	coor.y = 0;
	map.items = 0;
	while (map.map[coor.y] != NULL)
	{
		coor.x = 0;
		while (map.map[coor.y][coor.x] != '\n' && map.map[coor.y][coor.x] != 0)
		{
			if (map.map[coor.y][coor.x] == ITEMS[C])
				map.items++;
			coor.x++;
		}
		coor.y++;
	}
	return (map.items);
}

void	print_player(t_player *one, t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, one->img_s->img,
		one->pos.x * IMG_WIDTH, one->pos.y * IMG_HEIGHT);
}

int	reload_map(t_game	*game)
{
	print_floor(*game->map, game->imgs[F], game->mlx);
	print_static(*game->map, game->imgs, game->mlx);
	print_player(game->player, game->mlx);
	return (0);
}
