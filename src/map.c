/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:40:00 by iortego-          #+#    #+#             */
/*   Updated: 2023/07/10 17:34:30 by iortego-         ###   ########.fr       */
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
		while (map.map[coor.y][coor.x] != 0)
		{
			// if (map.map[coor.y][coor.x] == ITEMS[F]) 
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
		while (map.map[coor.y][coor.x] != 0)
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

void	print_player(t_map map, t_player *one, t_mlx *mlx)
{
	t_coor	coor;

	coor.y = 0;
	while (map.map[coor.y] != NULL)
	{
		coor.x = 0;
		while (map.map[coor.y][coor.x] != 0)
		{
			if (map.map[coor.y][coor.x] == ITEMS[P]) 
				mlx_put_image_to_window(mlx->mlx, mlx->win, one->img,
					coor.x * IMG_WIDTH, coor.y * IMG_HEIGHT);
			coor.x++;
		}
		coor.y++;
	}
}

void	reload_map(t_map map, t_img *images, t_player *one, t_mlx *mlx)
{
	print_floor(map, images[F], mlx);	
	print_static(map, images, mlx);	
	print_player(map, one, mlx);	
	// mlx_loop(mlx->mlx);
}
