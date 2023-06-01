/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:55:39 by iortego-          #+#    #+#             */
/*   Updated: 2023/06/01 18:19:55 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	img.path = "./xpm/pato.xpm";
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");


	img.img = mlx_xpm_file_to_image(mlx, img.path, &img.width, &img.height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0,  1080 / 2 - img.height / 2);

	mlx_loop(mlx);
}
