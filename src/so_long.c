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
int	main(void)
{
	t_img		*imgs;
	t_mlx		mlx;
	t_map		*map;
	t_player	*one;
	
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello world!");
	map = malloc(sizeof(t_map));	
	if (!map)
		return (printf("Ha fallao el maloc loko"),0); 
	map = (t_map *) open_file(MAP_PATH, (void *)get_map);
	if (map == NULL)
		return (1);
	imgs = get_imgs(mlx.mlx, "./img/");
	if (!imgs)
		return (1);
	one = player_constructor(*map, &imgs[P]);
	if (one == NULL)
		return (1);
	reload_map(*map, imgs, one, mlx.mlx);
	// mlx_key_hook(mlx.win, listener, &mlx);
	//
	// mlx_loop(mlx.mlx);
	return(0);
}
