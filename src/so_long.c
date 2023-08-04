/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:55:39 by iortego-          #+#    #+#             */
/*   Updated: 2023/07/23 15:36:12 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_img	img;
// 	int		offset;
// 	int		y;
// 	int		x;
//
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hola Alvaro que tal estas?");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	mlx_loop(mlx);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// }
t_game	*init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit(1);
	game->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!game->mlx)
		exit(1);
	game->map = open_file(MAP_PATH, (void *)get_map);
	if (!game->map || !parse_map(game->map))
		exit(1);
	game->mlx->mlx = mlx_init();
	game->mlx->win = mlx_new_window(game->mlx->mlx, game->map->dim.x
			* IMG_WIDTH, game->map->dim.y * IMG_HEIGHT, "so_long");
	game->imgs = get_imgs(game->mlx, IMG_PATH);
	if (!game->imgs)
		exit(1);
	game->player = player_constructor(*game->map, &game->imgs[P]);
	if (!game->player)
		exit(1);
	return (game);
}

int	main(void)
{
	t_game		*game;

	game = init();
	reload_map(game);
	mlx_key_hook(game->mlx->win, listener, game);
	mlx_loop_hook(game->mlx->mlx, reload_map, game);
	mlx_hook(game->mlx->win, 17, 0L, (int (*)()) exit, 0);
	mlx_loop(game->mlx->mlx);
	return (0);
}
